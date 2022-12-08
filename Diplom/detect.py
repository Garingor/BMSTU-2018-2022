from packs.django import detect as detect_django_project
from packs.flask import detect as detect_flask_project
from packs.react import detect as detect_react_project
from packs.django.classDjango import DjangoInformation as django_structure
from packs.flask.classFlask import FlaskInformation as flask_structure
from utility import utility as ut


def detector(dir_project):
    django_checker = detect_django_project.detector_django_project(dir_project)
    react_checker = False

    if django_checker is True:
        django_str = django_structure()
        django_str.set_workdir(dir_project.split("/")[len(dir_project.split("/")) - 1])
        ut.get_dependendencies_version(dir_project)
        django_str = detect_django_project.detect_databases_django(dir_project, django_str)
        react_checker = detect_react_project.detector_react_project(dir_project)
        return django_str, 'django', react_checker

    flask_checker = detect_flask_project.detector_flask_project(dir_project)

    if flask_checker is True:
        flask_str = flask_structure()
        flask_str.set_workdir(dir_project.split("/")[len(dir_project.split("/")) - 1])
        ut.get_dependendencies_version(dir_project)
        flask_str = detect_flask_project.detect_databases_flask(dir_project, flask_str)
        return flask_str, 'flask', react_checker

    return None, '', react_checker
