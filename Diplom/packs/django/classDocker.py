class Docker_Information_django(object):
    def __init__(self, basicimage='python:3', pythonunbuffered='1', pythondontwritebytecode='1'):
        self.basicimage = basicimage
        self.pythonunbuffered = pythonunbuffered
        self.pythondontwritebytecode = pythondontwritebytecode

    def get_basicimage(self):
        return self.basicimage

    def get_pythonunbuffered(self):
        return self.pythonunbuffered

    def get_pythondontwritebytecode(self):
        return self.pythondontwritebytecode
