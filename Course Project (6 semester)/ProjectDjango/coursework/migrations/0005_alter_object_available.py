# Generated by Django 3.2.7 on 2021-09-23 08:55

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('coursework', '0004_auto_20210923_0852'),
    ]

    operations = [
        migrations.AlterField(
            model_name='object',
            name='available',
            field=models.CharField(choices=[('Yes', 'Yes'), ('No', 'No')], max_length=200, null=True),
        ),
    ]
