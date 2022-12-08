import detect
from packs.django import create as create_django
from packs.flask import create as create_flask
from packs.react import create as create_react
from packs.react import detect as detect_react
from packs.django.classDocker import Docker_Information_django
from packs.flask.classDocker import Docker_Information_flask
from packs.react.classDocker import Docker_Information_react
from utility import docker_utility as docker_ut
from utility import utility as ut
import PySimpleGUI as sg
from datetime import datetime


def main():
    layout = [
        [sg.Text('Проект         '), sg.InputText(), sg.FolderBrowse('Обзор')],
        [sg.Text('База данных'), sg.InputText(), sg.FolderBrowse('Обзор'), sg.Checkbox('необходимо создать контейнер')],
        [sg.Output(size=(88, 20))],
        [sg.Submit('Запуск'), sg.Cancel('Выход')]
    ]

    window = sg.Window('Контейнеризация приложения', layout)
    while True:
        event, values = window.read()

        if event in (None, 'Выход'):
            break

        start_time = datetime.now()
        if event == 'Запуск':
            dir_project = values[0]

            dir_db = ut.input_directory_db(values[1], values[2])

            struct, name, react_flag = detect.detector(dir_project)

            match name:
                case 'django':
                    print("Найден фреймворк django")
                    docker_str = Docker_Information_django()
                    create_django.createdockerfile(docker_str, struct, dir_project, react_flag)
                case 'flask':
                    print("Найден фреймворк flask")
                    docker_str = Docker_Information_flask()
                    create_flask.createdockerfile(docker_str, struct, dir_project)
                case '':
                    print('фреймворк не найден')
                    exit(0)

            if react_flag:
                print("Найден React")
                react_str = detect_react.detector(dir_project)
                docker_str = Docker_Information_react()
                create_react.createdockerfile(docker_str, react_str, dir_project)

            docker_ut.build_docker_container(dir_project, struct.get_workdir())

            dbs = struct.dbs
            i = 0
            for db in dbs:
                match db['ENGINE']:
                    case 'postgres':
                        print("Найдена база данных postgres")
                        if values[2]:
                            docker_ut.launch_docker_network()
                            docker_ut.launch_db_container_postgres(db, dir_db, i)
                    case 'sqlite3':
                        print("Найдена база данных sqlite3")
                    case 'sqlite':
                        print("Найдена база данных sqlite")
                    case 'mysql':
                        print("Найдена база данных mysql")
                        if values[2]:
                            docker_ut.launch_docker_network()
                            docker_ut.launch_db_container_mysql(db, dir_db, i)
                i += 1

            docker_ut.launch_docker_container(struct.get_workdir())

            print(docker_ut.docker_port())

            #print(datetime.now() - start_time)


if __name__ == "__main__":
    main()

#комментарии readme инструкции (документация) необходимо создать контейнер volume react