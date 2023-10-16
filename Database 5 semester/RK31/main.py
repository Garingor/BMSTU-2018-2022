# вариант 3
import psycopg2

conn = psycopg2.connect(dbname='rk3', user='postgres', password='2468', host='localhost')
cursor = conn.cursor()

def f1():
    try:
        cursor.execute("select id, min(hd) from employee where department = 'Бухгалтерия'")
        for row in cursor:
            print(row, "\n")
    except:
        print("NOT OK\n")

def f2():
    try:
        cursor.execute("select emp.id from ( select id, count(*) as count_t from timeT tt join employee emp on emp.id = tt.id group by tt.id, tt.dateS, where tt.type = 2 ) t join employee emp on t.id = emp.id where t.count_t > 3")
        for row in cursor:
            print(row, "\n")
    except:
        print("NOT OK\n")

def f3():
    try:
        cursor.execute("select emp.id from (select emp.id, max(tt.timeS) as last_call from employee emp join timeT tt on emp.id = tt.id where tt.type = 1 and tt.dateS = current_date ) t join employee emp on t.id = emp.i group by t.id where max(t.last_call)")
        for row in cursor:
            print(row, "\n")
    except:
        print("NOT OK\n")

cursor.close()
conn.close()
