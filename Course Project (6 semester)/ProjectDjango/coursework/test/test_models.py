from django.test import TestCase, Client
from django.urls import reverse
from ..factories import RoomFactory
from ..forms import *


class TestModelRooms(TestCase):
    def setUp(self):
        self.client = Client()
        self.room_url = reverse('room')

    def test_room_POST_adds_new_room_MOCK(self):
        posts = RoomFactory.create_batch(1)
        response = self.client.post(reverse('create_room'), {
            'floor': posts[0].floor,
            'number': posts[0].number,
        })

        self.assertEquals(response.status_code, 302)

