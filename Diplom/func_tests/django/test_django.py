from packs.django import detect as dt
from packs.django.classDjango import DjangoInformation as django_structure
import unittest


class TestDjangoMethods(unittest.TestCase):
    def test_no_directory(self):
        with self.assertRaises(SystemExit) as cm:
            dt.detector_django_project('')
        self.assertEqual(cm.exception.code, 1)

    def test_no_directory_databases(self):
        with self.assertRaises(SystemExit) as cm:
            dt.detect_databases_django('', None)
        self.assertEqual(cm.exception.code, 1)

    def test_no_database(self):
        django_str = django_structure()
        dir_project = '/Users/egor/Documents/GitHub/' \
                      'diplom_IU7_BMSTU/tests/demodjango\ copy/mysite'
        django_str.set_workdir(dir_project.split("/")
                               [len(dir_project.split("/")) - 1])
        with self.assertRaises(SystemExit) as cm:
            dt.detect_databases_django(dir_project, django_str)
        self.assertEqual(cm.exception.code, 1)

    def test_add_database(self):
        message = "базы данных отличаются"
        django_str = django_structure()
        dir_project = '/Users/egor/Documents/GitHub/' \
                      'diplom_IU7_BMSTU/tests/demodjango/mysite'
        django_str.set_workdir(dir_project.split("/")
                               [len(dir_project.split("/")) - 1])
        django_str_correct = django_structure()
        django_str_correct.set_workdir(dir_project.split("/")
                               [len(dir_project.split("/")) - 1])

        struct = dt.detect_databases_django(dir_project, django_str)

        django_str_correct.update_dbs({'ENGINE': 'postgres', 'NAME': "testdb", 'USER': "postgres",
                                       'PASSWORD': "2468", 'HOST': "db", 'PORT': '5432'})

        self.assertEqual(struct.dbs, django_str_correct.dbs)

if __name__ == '__main__':
    unittest.main()

