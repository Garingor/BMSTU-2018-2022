# Generated by Django 3.2.7 on 2021-09-23 10:45

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('coursework', '0006_remove_object_available'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='room',
            name='object',
        ),
        migrations.AddField(
            model_name='object',
            name='room',
            field=models.ForeignKey(null=True, on_delete=django.db.models.deletion.SET_NULL, to='coursework.room'),
        ),
    ]
