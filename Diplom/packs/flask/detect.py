import os
import os.path
import re
from utility import utility as ut

def detector_flask_project(dir_project):
    try:
        os.listdir(dir_project)
    except FileNotFoundError:
        #print("Нет такой директории: " + dir_project)
        exit(1)
    else:
        for root, dirs, files in os.walk(dir_project):
            for file in files:
                try:
                    with open(root + '/' + file) as f:
                        for line in f.readlines():
                            if 'import Flask' in line:
                                return True
                except:
                    continue
        return False


def detect_databases_flask(dir_project, flask_str):
    path = os.path.exists(dir_project)

    if path is False:
        # print("Не найдена директория: " + dir_project)
        exit(1)

    db = {}
    flag_add = False
    pattern = re.compile("(\w+)://(.+):(.+)+@(.+):(.+)+/(.+)\"")
    for root, dirs, files in os.walk(dir_project):
        for file in files:
            try:
                with open(root + '/' + file) as f:
                    for line in f.readlines():
                        if flag_add:
                            line = line.split(" ")
                            line = line[len(line) - 1]
                        match = re.findall(pattern, line)
                        if match:
                            db['ENGINE'] = match[0][0]
                            db['USER'] = match[0][1]
                            db['PASSWORD'] = match[0][2]
                            db['HOST'] = match[0][3]
                            db['PORT'] = match[0][4]
                            db['NAME'] = match[0][5]
                            flag_add = True
                            flask_str.update_dbs(db)
                            db = {}
            except UnicodeDecodeError:
                continue
        if flag_add is True:
            break

    pattern = re.compile("(.+)=\s'(.+):///(.+)'")
    for root, dirs, files in os.walk(dir_project):
        for file in files:
            try:
                with open(root + '/' + file) as f:
                    for line in f.readlines():
                        match = re.findall(pattern, line)
                        if match:
                            db['ENGINE'] = match[0][1]
                            db['NAME'] = match[0][2]
                            flag_add = True
                            flask_str.update_dbs(db)
                            db = {}
            except UnicodeDecodeError:
                continue
        if flag_add is True:
            break

    if flag_add is False:
        #print("База данных не найдена")
        exit(1)

    return flask_str

