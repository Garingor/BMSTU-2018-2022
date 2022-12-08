from rest_framework import viewsets

from .serializers import *
from ..models import *


class RoomViewSet(viewsets.ModelViewSet):

    queryset = Room.objects.all()
    serializer_class = RoomSerializer


class ObjectViewSet(viewsets.ModelViewSet):

    queryset = Object.objects.all()
    serializer_class = ObjectSerializer


class EmployeeViewSet(viewsets.ModelViewSet):

    queryset = Employee.objects.all()
    serializer_class = EmployeeSerializer


class LegalEntityViewSet(viewsets.ModelViewSet):

    queryset = LegalEntity.objects.all()
    serializer_class = LegalEntitySerializer
