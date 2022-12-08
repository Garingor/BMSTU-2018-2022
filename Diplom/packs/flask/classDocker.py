class Docker_Information_flask(object):
    def __init__(self, basicimage='python:3'):
        self.basicimage = basicimage

    def get_basicimage(self):
        return self.basicimage
