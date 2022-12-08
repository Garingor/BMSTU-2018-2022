from django.db import models
from django.db.models.signals import post_save, pre_delete, post_delete
from django.dispatch import receiver
from django.core.files import File
from PIL import Image, ImageDraw
import qrcode
from io import BytesIO

from dataclasses import dataclass


@dataclass
class Room:
    floor: int
    number: int


class LegalEntity(models.Model):
    CATEGORY = (
        ('М', 'М'),
        ('Ж', 'Ж')
    )
    name = models.CharField(max_length=200, null=True)
    surname = models.CharField(max_length=200, null=True)
    # patronymic = models.CharField(max_length=200, null=True)  # отчество
    address = models.CharField(max_length=200, null=True)
    inn = models.IntegerField(null=True)
    # sex = models.CharField(max_length=200, null=True, choices=CATEGORY)
    # dob = models.DateField(null=True)
    series_passport = models.IntegerField(null=True)
    number_passport = models.IntegerField(null=True)
    employee_number = models.PositiveIntegerField(default=0)

    def __str__(self):
        return self.name


class Employee(models.Model):
    CATEGORY = (
        ('М', 'М'),
        ('Ж', 'Ж')
    )
    name = models.CharField(max_length=200, null=True)
    surname = models.CharField(max_length=200, null=True)
    # patronymic = models.CharField(max_length=200, null=True)  # отчество
    address = models.CharField(max_length=200, null=True)
    inn = models.IntegerField(null=True)
    # sex = models.CharField(max_length=200, null=True, choices=CATEGORY)
    # dob = models.DateField(null=True)
    series_passport = models.IntegerField(null=True)
    number_passport = models.IntegerField(null=True)
    position = models.CharField(max_length=200, null=True)

    # legalentity = models.ForeignKey(LegalEntity, null=True, on_delete=models.SET_NULL)

    def __str__(self):
        return self.name


# @receiver(post_save, sender=Employee)
# def inc_employee_number(sender, instance, created, **kwargs):
#     if created:
#         instance.legalentity.employee_number += 1
#         instance.legalentity.save()
#
#
# @receiver(post_delete, sender=Employee)
# def dec_employee_number(sender, instance, **kwargs):
#     instance.legalentity.employee_number -= 1
#     instance.legalentity.save()


class Room(models.Model):
    floor = models.IntegerField(null=True)
    number = models.IntegerField(null=True)

    def __str__(self):
        return str(self.floor) + " " + str(self.number)


class Object(models.Model):
    CATEGORY = (
        ('новый', 'новый'),
        ('б/у', 'б/у')
    )

    CATEGORY2 = (
        ('да', 'да'),
        ('нет', 'нет')
    )

    name = models.CharField(max_length=200, null=True)
    description = models.CharField(max_length=200, null=True)
    condition = models.CharField(max_length=200, null=True, choices=CATEGORY)
    purchase_date = models.DateField(null=True)
    # employee = models.ForeignKey(Employee, null=True, on_delete=models.SET_NULL, default='------')
    # room = models.ForeignKey(Room, null=True, on_delete=models.SET_NULL)
    availability = models.CharField(max_length=200, null=True, choices=CATEGORY2)

    def __str__(self):
        return self.name
