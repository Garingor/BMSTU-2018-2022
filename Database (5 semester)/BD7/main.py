from py_linq import Enumerable

students = Enumerable([{ 'name': 'Joe Smith', 'mark': 80}, { 'name': 'Joanne Smith', 'mark': 90}])
names = students.select(lambda x: x['name'])

print(names)