from baseclass import DBInformation


class FlaskInformation(DBInformation):
    def __init__(self, workdir=None, port=80):
        super().__init__()
        self.workdir = workdir
        self.port = port

    def update_dbs(self, db):
        super().update_dbs(db)

    def get_workdir(self):
        return self.workdir

    def set_workdir(self, workdir):
        self.workdir = workdir

    def get_port(self):
        return self.port

    def set_port(self, port):
        self.workdir = port