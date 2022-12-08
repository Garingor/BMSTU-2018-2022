import os
import os.path
from utility import utility as ut
from packs.react.classReact import ReactInformation as react_structure


def detector_react_project(dir_project):
    try:
        os.listdir(dir_project)
    except FileNotFoundError:
        print("Нет такой директории: " + dir_project)
        exit(0)
    else:
        for root, dirs, files in os.walk(dir_project):
            for file in files:
                try:
                    with open(root + '/' + file) as f:
                        for line in f.readlines():
                            if 'import React' in line:
                                return True
                except:
                    continue
        return False


# def detect_node_version(react_str):
#     react_str.set_node_version(os.popen("node -v").read().split("v")[1])
#
#
# def detect_package_json(dir_project, react_str):
#     react_str.set_package_json(ut.find('package.json', dir_project))

def detector(dir_project):
    react_str = react_structure()
    package_json = ut.find('package.json', dir_project)
    react_str.set_node_version(os.popen("node -v").read().split("v")[1])
    react_str.set_package_json(package_json)
    react_str.set_workdir(package_json.split("/")[-2])
    return react_str