# Generated by Django 3.2.7 on 2021-09-23 14:59

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('coursework', '0007_auto_20210923_1045'),
    ]

    operations = [
        migrations.AlterField(
            model_name='employee',
            name='dob',
            field=models.CharField(max_length=200, null=True),
        ),
    ]
