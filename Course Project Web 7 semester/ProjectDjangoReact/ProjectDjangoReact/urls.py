"""ProjectDjangoReact URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""

from django.contrib import admin
from django.urls import path, include, re_path
from django.views.generic import TemplateView

import sys
sys.path.append(sys.path[0] + "/..")

from mainapp.views import *

from rest_framework_swagger.views import get_swagger_view

schema_view = get_swagger_view(title='Pastebin API')

from django.contrib.staticfiles.urls import staticfiles_urlpatterns

urlpatterns = [
    #path('admin/', admin.site.urls),
    path('auth/', include('djoser.urls')),
    path('auth/', include('djoser.urls.jwt')),

    path('', index),

    path('rooms/', rooms),
    path('rooms/<int:id>/', room_select),
    path('rooms/edit/<int:id>/', room_edit),
    path('rooms/add', room_add),

    path('objects/', objects),
    path('objects/<int:id>/', object_select),
    path('objects/edit/<int:id>/', object_edit),
    path('objects/add', object_add),

    path('legalentities/', legalentities),
    path('legalentities/<int:id>/', legalentity_select),
    path('legalentities/edit/<int:id>/', legalentity_edit),
    path('legalentities/add', legalentity_add),

    path('employees/', employees),
    path('employees/<int:id>/', employee_select),
    path('employees/edit/<int:id>/', employee_edit),
    path('employees/add', employee_add),

    path('api/v1/', include('mainapp.api.urls')),
    path('api/v2/', schema_view),
]

urlpatterns += staticfiles_urlpatterns()

urlpatterns += [re_path(r'^.*', TemplateView.as_view(template_name='index.html'))]