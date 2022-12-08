import os
import time

def docker_port():
    return os.popen("docker port web").read().split(" ")[2]


def build_docker_container(dir_project, name):
    os.chdir(dir_project)
    os.system("docker build -t " + name + " .")


def launch_docker_network():
    os.system("docker network rm mynetwork")
    os.system("docker network create mynetwork")


def launch_docker_container(name):
    os.system("docker run -d -P --name web --network=mynetwork " + name)


def launch_db_container_postgres(db, dir_db, i):
    os.chdir(dir_db)
    os.system("pg_dump -Fc " + db['NAME'] + " > db.dump")


    os.system("docker run -d --name db" + str(i) + " -p 543" + str(i) + ":5432"
                  " -e POSTGRES_USER=" + db['USER'] + " -e "
                  "POSTGRES_PASSWORD=" + db['PASSWORD'] + " -e "
                  "POSTGRES_DB=" + db['NAME'] +
                  " -v " + dir_db + " --network=mynetwork postgres:" +
                  os.popen('postgres --version').read().split(" ")[2].split("'\n")[0])

    time.sleep(10)
    os.system("docker cp db.dump db" + str(i) + ":" + dir_db)
    os.system("docker exec db" + str(i) + " pg_restore -U " + db['USER'] +
              "  -d  " + db['NAME'] + " " + dir_db + "/db.dump")

    #os.system("docker exec web psql -U " + db['USER'] + " " + db['NAME'] + " < dumpfile.sql")
    #os.system("docker cp dumpfile.sql db" + str(i) + ":" + dir_db)
    #" -e PGDATA=/var/lib/postgresql/data/pgdata -d -v \"" + dir_db + "\":/var/lib/postgresql/data --network=mynetwork postgres:" +


def launch_db_container_mysql(db, dir_db, i):
    os.chdir(dir_db)
    os.system("mysql -p -u" + db['USER'] + " " + db['NAME'] + " < db.dump")
    os.system("docker cp db.dump db" + str(i) + ":" + dir_db)

    os.system("docker run -d --name db" + str(i) + " -p 543" + str(i) + ":3306" +
                  " -e MYSQL_USER=" + db['USER'] + " -e "
                  "MYSQL_PASSWORD=" + db['PASSWORD'] + " -e "
                  "MYSQL_DB=" + db['NAME'] +
                  " -v " + dir_db + " --network=mynetwork mysql/mysql-server:" +
                  os.popen('mysql --version').read().split(" ")[2])

    time.sleep(10)
    os.system("docker cp db.dump db" + str(i) + ":" + dir_db)
    os.system("docker exec db" + str(i) + " sh -c \'exec mysql -u" + db['USER'] + " -p" + db['PASSWORD'] + db['NAME'] + " \' < " + dir_db + "/db.dump")

# def launch_docker_container(name):
#     os.system("docker run -d -P --name web --link db:db -i -t  " + name)

# def launch_db_container_postgres(struct, dir_db):
#     os.system("docker run -d --name db -e "
#               "POSTGRES_USER=" + struct.get_dbs()['USER'] + " -e "
#               "POSTGRES_PASSWORD=" + struct.get_dbs()['PASSWORD'] + " -e "
#               "POSTGRES_DB=" + struct.get_dbs()['NAME'] +
#               " -v " + dir_db + " postgres:13")

#docker run --name db -p 5432:5432 -e POSTGRES_USER=postgres -e POSTGRES_PASSWORD=2468 -e POSTGRES_DB=testdb -v /Users/egor/Library/Application/Support/Postgres/var-13 postgres:13
