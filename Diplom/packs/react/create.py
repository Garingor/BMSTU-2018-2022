import os


def createdockerfile(docker_str, react_str, dir_project):
    os.chdir(dir_project)
    f = open('dockerfile', 'a')
    f.write('\n\nFROM ' + docker_str.get_basicimage() + react_str.get_node_version() +
            '\nRUN mkdir /' + react_str.get_workdir() +
            '\nWORKDIR /' + react_str.get_workdir() +
            '\nCOPY /' + react_str.get_workdir() + '/package.json /' + react_str.get_workdir() +
            '\nCOPY /' + react_str.get_workdir() + ' /' + react_str.get_workdir() +
            '\nRUN npm install' +
            '\nEXPOSE ' + str(react_str.get_port()) +
            '\nCMD ["npm", "start"]')

    f.close()

#FROM node:14.17.5
#RUN mkdir /react
#WORKDIR /react
#COPY /frontend/package.json /react
#COPY /frontend /react
#RUN npm install
#EXPOSE 3000
#CMD ["npm", "start"]