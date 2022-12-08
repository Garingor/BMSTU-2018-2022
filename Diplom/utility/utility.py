import os


def find(name, path):
    for root, dirs, files in os.walk(path):
        if name in files:
            return os.path.join(root, name)
    return None


def get_dependendencies_version(dir_project):
    if not os.path.exists(dir_project):
        print("Нет такой директории: " + dir_project)
        exit(0)

    os.system("python3 -m pipreqs.pipreqs " + dir_project + " --force")


# def input_directory(value):
#     dir_project = value#"/Users/egor/Desktop/demo/mysite" #"/Users/egor/Desktop/demoflask"
#     # "/Users/egor/Documents/GitHub/BMSTU_WEB_7_sem_2021/ProjectDjangoReact/"#input("Введите полный путь до проекта: ")
#     # /Users/egor/Documents/GitHub/BMSTU_WEB_7_sem_2021/ProjectDjangoReact/
#
#     return dir_project

def input_directory_db(value, checkbox):
    if checkbox:
        return value#"/Users/egor/Library/Application/Support/Postgres/var-13"


    return None

