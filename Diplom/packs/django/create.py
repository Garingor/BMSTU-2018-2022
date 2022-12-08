import os


def createdockerfile(docker_str, django_str, dir_project, react_flag):
    os.chdir(dir_project)
    f = open('dockerfile', 'w')
    f.write('FROM ' + docker_str.get_basicimage() +
            '\nENV PYTHONDONTWRITEBYTECODE=' + docker_str.get_pythonunbuffered() +
            '\nENV PYTHONUNBUFFERED=' + docker_str.get_pythondontwritebytecode() +
            '\nWORKDIR /' + django_str.get_workdir() +
            '\nCOPY requirements.txt /' + django_str.get_workdir() + '/' +
            '\nRUN pip3 install -r requirements.txt' +
            '\nCOPY . /' + django_str.get_workdir() + '/' +
            '\nEXPOSE ' + str(django_str.get_port()))

    if react_flag is False:
        f.write('\nCMD ["python", "manage.py", "runserver", "0.0.0.0:' + str(django_str.get_port()) + '"]')

    f.close()


#CMD ["python", "manage.py", "runserver", "127.0.0.1:8000"]

# FROM python:3
# ENV PYTHONDONTWRITEBYTECODE=1
# ENV PYTHONUNBUFFERED=1
# WORKDIR /mysite
# COPY requirements.txt /mysite/
# RUN pip install -r requirements.txt
# COPY . /mysite/
# EXPOSE 5432
# CMD ["python", "manage.py", "runserver", "127.0.0.1:8000"]