import mimesis
import random

from mimesis import Person
from mimesis import Address
from mimesis import locales
from mimesis import Datetime
from mimesis import Business

from mimesis.enums import Gender
from mimesis.providers import address
from mimesis.providers import date
from mimesis.providers import business

address = Address(locales.EN)
person = Person(locales.EN)
date = Datetime(locales.EN)
business = Business(locales.EN)

count = int(input())

if count < 1:
    print('Вы ввели некорректное число генерируемых строк')
    exit()


f = open('tabliza.txt', 'w')

f.write("...\n")
for i in range(count):
    sex = random.choice([1, 0])
    status = random.choice([1, 0])
    if sex == 0:
        with person.override_locale(locales.EN):
            f.write(person.name(gender=Gender.FEMALE) + '\n')
            f.write(person.surname(gender=Gender.FEMALE) + '\n')
        with person.override_locale(locales.RU):
            f.write(person.telephone() + '\n')
        with person.override_locale(locales.EN):
            f.write(address.address() + '\n')
    else:
        with person.override_locale(locales.EN):
            f.write(person.name(gender=Gender.MALE) + '\n')
            f.write(person.surname(gender=Gender.MALE) + '\n')
        with person.override_locale(locales.RU):
            f.write(person.telephone() + '\n')
        with person.override_locale(locales.EN):
            f.write(address.address() + '\n')
    f.write(str(status) + '\n')
    if status == 1:
        input_data = date.date(start=1970, end=2010)
        f.write(str(input_data.day) + "\n")
        f.write(str(input_data.month) + "\n")
        f.write(str(input_data.year) + "\n")
    else:
        with person.override_locale(locales.EN):
            f.write(person.occupation() + "\n")
            f.write(business.company() + "\n")

    f.write("...\n")
f.close()

