from django.contrib import admin

# Register your models here.
from .models import *

admin.site.register(Room)
admin.site.register(Object)
admin.site.register(LegalEntity)
admin.site.register(Employee)
