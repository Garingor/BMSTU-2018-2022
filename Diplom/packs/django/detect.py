import os
import os.path
import re
from utility import utility as ut


def detector_django_project(dir_project):
    try:
        file_list = os.listdir(dir_project)
    except FileNotFoundError:
        #print("Нет такой директории: " + dir_project)
        exit(1)
    else:
        if "manage.py" in file_list:
            return True
        else:
            return False


def detect_databases_django(dir_project, django_str):
    settingspy = ut.find('settings.py', dir_project)

    if settingspy is None:
        print("Не найден файл: " + dir_project + '/settings.py')
        exit(1)

    db = {}
    flag_add = False
    flag_sqlite3 = False
    pattern = re.compile("'(\w+)':\s*([0-9]+|'(.+)')")
    with open(settingspy) as f:
        for line in f.readlines():
            match = re.findall(pattern, line)
            if match and 'django.contrib.auth.password_validation.' not in match[0][1] and \
                    'BACKEND' not in match[0][0]:
                if 'django.db.backends.postgresql_psycopg2' in match[0][1]:
                    db['ENGINE'] = 'postgres'
                    continue
                if 'django.db.backends.sqlite3' in match[0][1]:
                    db['ENGINE'] = 'sqlite3'
                    django_str.update_dbs(db)
                    db = {}
                    flag_add = True
                    flag_sqlite3 = True
                    continue
                if 'django.db.backends.mysql' in match[0][1]:
                    db['ENGINE'] = 'mysql'
                    continue

                if flag_sqlite3:
                    continue

                db[match[0][0]] = match[0][1].replace("'", "")

                if match[0][0] == 'PORT':
                    django_str.update_dbs(db)
                    db = {}
                    flag_add = True

    if flag_add is False:
        print("База данных не найдена")
        exit(1)

    return django_str
