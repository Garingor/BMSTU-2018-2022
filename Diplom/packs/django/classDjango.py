from baseclass import DBInformation


class DjangoInformation(DBInformation):
    def __init__(self, workdir=None, port=8000):
        super().__init__()
        self.workdir = workdir
        self.port = port

    def update_dbs(self, db):
        super().update_dbs(db)

    def get_dbs(self):
        super().get_dbs()

    def get_workdir(self):
        return self.workdir

    def set_workdir(self, workdir):
        self.workdir = workdir

    def get_port(self):
        return self.port

    def set_port(self, port):
        self.workdir = port
