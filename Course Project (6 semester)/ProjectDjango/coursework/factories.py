import factory
import factory.fuzzy

from .models import Room


class RoomFactory(factory.Factory):
    class Meta:
        model = Room

    floor = factory.Faker('random_int')
    number = factory.Faker('random_int')

