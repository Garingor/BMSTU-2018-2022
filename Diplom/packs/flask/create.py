import os


def createdockerfile(docker_str, flask_str, dir_project):
    os.chdir(dir_project)
    f = open('dockerfile', 'w')
    f.write('FROM ' + docker_str.get_basicimage() +
            '\nWORKDIR /' + flask_str.get_workdir() +
            '\nCOPY requirements.txt /' + flask_str.get_workdir() + '/' +
            '\nRUN pip3 install -r requirements.txt' +
            '\nCOPY . /' + flask_str.get_workdir() + '/' +
            '\nEXPOSE ' + str(flask_str.get_port()) +
            '\nCMD ["python3", "app.py"]')

    f.close()

    # FROM tiangolo / uwsgi - nginx - flask: python3.6 - alpine3.7
    # RUN apk - -update add bash nano
    # ENV STATIC_URL / static
    # ENV STATIC_PATH / var / www / app / static
    # COPY. / requirements.txt / var / www / requirements.txt
    # RUN pip install - r / var / www / requirements.txt