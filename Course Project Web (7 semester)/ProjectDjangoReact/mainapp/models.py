from django.db import models
from django.db.models.signals import post_save, post_delete
from django.dispatch import receiver
from django.contrib.auth.models import AbstractBaseUser, PermissionsMixin, BaseUserManager


class UserAccountManager(BaseUserManager):
    def create_user(self, email, password=None, **extra_fields):
        if not email:
            raise ValueError('Адрес электронной почты обязателен')

        email = self.normalize_email(email)
        user = self.model(email=email, **extra_fields)

        user.set_password(password)
        user.save()

        return user


class UserAccount(AbstractBaseUser, PermissionsMixin):
    email = models.EmailField(max_length=255, unique=True)
    name = models.CharField(max_length=255)
    is_active = models.BooleanField(default=True)
    is_staff = models.BooleanField(default=False)

    objects = UserAccountManager()

    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = ['name']

    def get_full_name(self):
        return self.name

    def get_short_name(self):
        return self.name

    def __str__(self):
        return self.email


class LegalEntity(models.Model):
    name = models.CharField(max_length=200, verbose_name='Имя юр лица', null=True)
    surname = models.CharField(max_length=200, verbose_name='Фамилия юр лица', null=True)
    patronymic = models.CharField(max_length=200, verbose_name='Отчество юр лица', null=True)
    address = models.CharField(max_length=200, verbose_name='Адрес юр лица', null=True)
    inn = models.IntegerField(null=True, verbose_name='ИНН юр лица')
    series_passport = models.IntegerField(null=True, verbose_name='Серия паспорта юр лица')
    number_passport = models.IntegerField(null=True, verbose_name='Номер паспорта юр лица')
    employee_number = models.PositiveIntegerField(default=0, verbose_name='кол-во подчиненных юр лица')

    def __str__(self):
        return self.name


class Employee(models.Model):
    name = models.CharField(max_length=200, verbose_name='Имя сотрудника', null=True)
    surname = models.CharField(max_length=200, verbose_name='Фамилия сотрудника', null=True)
    patronymic = models.CharField(max_length=200, verbose_name='Отчество сотрудника', null=True)  # отчество
    address = models.CharField(max_length=200, verbose_name='Адрес сотрудника', null=True)
    inn = models.IntegerField(null=True, verbose_name='ИНН сотрудника')
    series_passport = models.IntegerField(null=True, verbose_name='Серия паспорта сотрудника')
    number_passport = models.IntegerField(null=True, verbose_name='Номер паспорта сотрудника')
    position = models.CharField(max_length=200, verbose_name='Должность сотрудника', null=True)
    legalentity = models.ForeignKey(LegalEntity, verbose_name='Начальник сотрудника', null=True, on_delete=models.SET_NULL)

    def __str__(self):
        return self.name


@receiver(post_save, sender=Employee)
def inc_employee_number(sender, instance, created, **kwargs):
    if created:
        instance.legalentity.employee_number += 1
        instance.legalentity.save()


@receiver(post_delete, sender=Employee)
def dec_employee_number(sender, instance, **kwargs):
    instance.legalentity.employee_number -= 1
    instance.legalentity.save()


class Room(models.Model):
    name = models.CharField(max_length=200, verbose_name='Имя помещения', null=True)
    floor = models.IntegerField(null=True, verbose_name='Этаж помещения')
    number = models.IntegerField(null=True, verbose_name='Номер помещения')

    def __str__(self):
        return "этаж:" + str(self.floor) + " номер:" + str(self.number)


class Object(models.Model):
    CATEGORY = (
        ('новый', 'новый'),
        ('б/у', 'б/у')
    )

    name = models.CharField(max_length=200, verbose_name='Название оборудования', null=True)
    description = models.CharField(max_length=200, verbose_name='Описание оборудования', null=True)
    condition = models.CharField(max_length=200, verbose_name='Состояние оборудования', null=True, choices=CATEGORY)
    date = models.DateField(auto_now=True, verbose_name='Дата внесения оборудования в базу')
    employee = models.ForeignKey(Employee, verbose_name='Кто пользуется оборудованием', null=True, on_delete=models.SET_NULL, default='------')
    room = models.ForeignKey(Room, verbose_name='Где оборудование', null=True, on_delete=models.SET_NULL)
    availability = models.BooleanField(default=False, verbose_name='Доступность оборудования')

    def __str__(self):
        return self.name