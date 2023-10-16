"""ProjectDjango URL Configuration

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
from django.urls import path, include
from coursework import views

urlpatterns = [
    path('api-auth/', include('rest_framework.urls')),

    path('admin/', admin.site.urls),
    path('', views.home, name='home'),
    path('objects/', views.objects, name='object'),
    path('employees/', views.employees, name='employee'),
    path('legalentities/', views.legalentities, name='legalentity'),
    path('rooms/', views.rooms, name='room'),

    path('create_employee/', views.create_employee, name='create_employee'),
    path('create_legalentity/', views.create_legalentity, name='create_legalentity'),
    path('create_room/', views.create_room, name='create_room'),
    path('create_object/', views.create_object, name='create_object'),


    path('update_employee/<str:pk>', views.update_employee, name='update_employee'),
    path('update_legalentity/<str:pk>', views.update_legalentity, name='update_legalentity'),
    path('update_room/<str:pk>', views.update_room, name='update_room'),
    path('update_object/<str:pk>', views.update_object, name='update_object'),


    path('delete_employee/<str:pk>', views.delete_employee, name='delete_employee'),
    path('delete_legalentity/<str:pk>', views.delete_legalentity, name='delete_legalentity'),
    path('delete_room/<str:pk>', views.delete_room, name='delete_room'),
    path('delete_object/<str:pk>', views.delete_object, name='delete_object'),

    path('register/', views.register_page, name='register'),
    path('login/', views.login_page, name='login'),
    path('logout/', views.logout_user, name='logout'),

    path('get_employee/<str:pk>', views.get_employee, name='get_employee'),
    path('get_legalentity/<str:pk>', views.get_legalentity, name='get_legalentity'),
    path('get_room/<str:pk>', views.get_room, name='get_room'),
    path('get_object/<str:pk>', views.get_object, name='get_object'),

    path('get_qr_object/<str:pk>', views.get_qr_object, name='get_qr_object'),
    #path('qr/', views.view_qr)

]
