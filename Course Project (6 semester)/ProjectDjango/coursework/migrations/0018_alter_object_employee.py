# Generated by Django 3.2.7 on 2021-09-25 15:40

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('coursework', '0017_alter_object_employee'),
    ]

    operations = [
        migrations.AlterField(
            model_name='object',
            name='employee',
            field=models.ForeignKey(blank=True, default='------', null=True, on_delete=django.db.models.deletion.SET_NULL, to='coursework.employee'),
        ),
    ]
