# вариант 2
import psycopg2

conn = psycopg2.connect(dbname='rk3', user='postgres', password='2468', host='localhost')
cursor = conn.cursor()

def f1():
    try:
        cursor.execute("select distinct employee.department from department where DATEDIFF(year, department.bd, current_date) >= 25;")
        for row in cursor:
            print(row, "\n")
    except:
        print("NOT OK")

def f2():
    try:
        cursor.execute("select timeT.id, min(timeT.timeS) as min_t from timeT where timeT.type = 1 and timeT.dataS = current_date group by id order by min_t")
        for row in cursor:
            print(row, "\n")
    except:
        print("NOT OK")

def f3():
    try:
        cursor.execute("select employee.id from ( select people.id, count(*) from ( select id, min(timeT.timeS) as Ftime from timeT group by id ) as people where people.Ftime > '9:00' group by people.id ) count_people join employee emp on count_people.id = emp.id where count >= 5")
        for row in cursor:
            print(row, "\n")
    except:
        print("NOT OK")

cursor.close()
conn.close()

