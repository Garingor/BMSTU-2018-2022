from packs.flask import detect as dt
from packs.flask.classFlask import FlaskInformation as flask_structure
import unittest


class TestReactMethods(unittest.TestCase):
    def test_no_directory(self):
        with self.assertRaises(SystemExit) as cm:
            dt.detector_flask_project('')
        self.assertEqual(cm.exception.code, 1)

    def test_no_directory_databases(self):
        with self.assertRaises(SystemExit) as cm:
            dt.detect_databases_flask('', None)
        self.assertEqual(cm.exception.code, 1)

    def test_no_database(self):
        flask_str = flask_structure()
        dir_project = '/Users/egor/Documents/GitHub/diplom_IU7_BMSTU/tests/demoflask\ copy'
        flask_str.set_workdir(dir_project.split("/")[len(dir_project.split("/")) - 1])
        with self.assertRaises(SystemExit) as cm:
            dt.detect_databases_flask(dir_project, flask_str)
        self.assertEqual(cm.exception.code, 1)

    def test_add_database(self):
        message = "базы данных отличаются"
        flask_str = flask_structure()
        dir_project = '/Users/egor/Documents/GitHub/' \
                      'diplom_IU7_BMSTU/tests/demoflask'
        flask_str.set_workdir(dir_project.split("/")
                               [len(dir_project.split("/")) - 1])
        flask_str_correct = flask_structure()
        flask_str_correct.set_workdir(dir_project.split("/")
                               [len(dir_project.split("/")) - 1])

        struct = dt.detect_databases_flask(dir_project, flask_str)

        flask_str_correct.update_dbs({'ENGINE': 'postgres', 'USER': 'username', 'PASSWORD': 'password',
                                        'HOST': 'localhost:5432', 'NAME': 'dbname'})

        self.assertEqual(struct.dbs, flask_str_correct.dbs)


if __name__ == '__main__':
    unittest.main()
