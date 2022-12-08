class ReactInformation(object):
    def __init__(self, node_version=None, package_json=None, workdir=None, port=3000):
        self.node_version = node_version
        self.package_json = package_json
        self.workdir = workdir
        self.port = port

    def get_node_version(self):
        return self.node_version

    def set_node_version(self, node_version):
        self.node_version = node_version

    def get_package_json(self):
        return self.package_json

    def set_package_json(self, package_json):
        self.package_json = package_json

    def get_workdir(self):
        return self.workdir

    def set_workdir(self, workdir):
        self.workdir = workdir

    def get_port(self):
        return self.port

    def set_port(self, port):
        self.port = port
