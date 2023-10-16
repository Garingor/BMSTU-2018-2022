from django.test import TestCase, Client
from django.urls import reverse, resolve
from django.template.defaultfilters import slugify
from ..views import *
from ..models import *
from ..decorators import *
from unittest import mock
from mock import patch
from ..factories import RoomFactory


class TestViewsRooms(TestCase):
    def setUp(self):
        self.client = Client()
        self.room_url = reverse('room')
        #self.room_url_delete = reverse('delete_room/')


    def test_room_list_GET(self):
        response = self.client.get(self.room_url)

        self.assertEquals(response.status_code, 200)
        self.assertTemplateUsed(response, 'accounts/rooms.html')

    def test_room_POST_adds_new_room(self):
        response = self.client.post(reverse('create_room'), {
            'floor': 13,
            'number': 2
        })

        self.assertEquals(response.status_code, 302)

    def test_room_POST_no_data(self):
        response = self.client.post(reverse('create_room'))

        self.assertEquals(response.status_code, 200)

    # def test_room_DELETE_no_id(self):
    #     response1 = self.client.post(reverse('create_room'), {
    #         'floor': 13,
    #         'number': 2
    #     })
    #     response2 = self.client.get(self.room_url)
    #     print(response2)
    #
    #     response3 = self.client.delete(self.room_url_delete)
    #
    #     self.assertEquals(response3.status_code, 404)

class TestViewsObjects(TestCase):
    def setUp(self):
        self.client = Client()
        self.object_url = reverse('object')

    def test_object_list_GET(self):
        response = self.client.get(self.object_url)

        self.assertEquals(response.status_code, 200)
        self.assertTemplateUsed(response, 'accounts/objects.html')

    def test_object_POST_adds_new_object(self):
        response = self.client.post(reverse('create_object'), {
            'name': "abc",
            'description': "qwe",
            'condition': "новый",
            'purchase_date': "06-06-2000",
            'availability': "да"
        })

        self.assertEquals(response.status_code, 200)


class TestViewsEmployees(TestCase):
    def setUp(self):
        self.client = Client()
        self.employee_url = reverse('employee')

    def test_employee_list_GET(self):
        response = self.client.get(self.employee_url)

        self.assertEquals(response.status_code, 200)
        self.assertTemplateUsed(response, 'accounts/employees.html')

    def test_employee_POST_adds_new_employee(self):
        response = self.client.post(reverse('create_object'), {
            'name': "abc",
            'surname': "qwe",
            'address': "qwe",
            'inn': 213124542,
            'series_passport': 2133,
            'number_passport': 234343,
            'employee_number': 0
        })

        self.assertEquals(response.status_code, 200)


class TestViewsLegalentity(TestCase):

    def setUp(self):
        self.client = Client()
        self.legalentity_url = reverse('legalentity')


    def test_legalentity_list_GET(self):
        response = self.client.get(self.legalentity_url)

        self.assertEquals(response.status_code, 200)
        self.assertTemplateUsed(response, 'accounts/legalentities.html')

    def test_employee_POST_adds_new_employee(self):
        response = self.client.post(reverse('create_object'), {
            'name': "abc",
            'surname': "qwe",
            'address': "qwe",
            'inn': 213124542,
            'series_passport': 2133,
            'number_passport': 234343,
            'position': "manager"
        })

        self.assertEquals(response.status_code, 200)
