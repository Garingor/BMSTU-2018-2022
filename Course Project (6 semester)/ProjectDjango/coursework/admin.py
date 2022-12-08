from django.contrib import admin

# Register your models here.
from .models import *

admin.site.register(Employee)
admin.site.register(LegalEntity)
admin.site.register(Room)
admin.site.register(Object)