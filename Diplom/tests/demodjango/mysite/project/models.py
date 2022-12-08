from django.db import models

class Empl(models.Model):
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
