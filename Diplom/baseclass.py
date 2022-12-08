class DBInformation(object):
    def __init__(self, dbs=None):
        if dbs is None:
            dbs = []
        self.dbs = dbs

    def display(self):
        print(self.dbs)

    def get_dbs(self):
        return self.dbs

    def update_dbs(self, db):
        self.dbs.append(db)
