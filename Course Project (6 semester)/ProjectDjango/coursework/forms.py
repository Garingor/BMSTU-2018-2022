from django.forms import ModelForm
from .models import *
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User
from django import forms


class EmployeeForm(ModelForm):
    class Meta:
        model = Employee
        fields = '__all__'


class LegalentityForm(ModelForm):
    class Meta:
        model = LegalEntity
        fields = '__all__'


class ObjectForm(ModelForm):
    class Meta:
        model = Object
        fields = '__all__'


class RoomForm(ModelForm):
    class Meta:
        model = Room
        fields = '__all__'


class CreateUserForm(UserCreationForm):
    class Meta:
        model = User
        fields = ['username', 'email', 'password1', 'password2']