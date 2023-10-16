from django.urls import path

from rest_framework import routers
from .views import *

router = routers.SimpleRouter()
router.register('rooms', RoomViewSet, basename='rooms')
router.register('objects', ObjectViewSet, basename='objects')
router.register('employees', EmployeeViewSet, basename='employees')
router.register('legalentities', LegalEntityViewSet, basename='legalentities')

urlpatterns = []
urlpatterns += router.urls
