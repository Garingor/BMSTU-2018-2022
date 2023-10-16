import psycopg2
from contextlib import closing

#1 Выполнить скалярный запрос
def get_profit_by_id_python():
    id_f = int(input("Введите id = "))
    with closing(psycopg2.connect(dbname='temp_blockchain', user='postgres',
                        password='2468', host='localhost')) as conn:
        with conn.cursor() as cursor:
            try:
                cursor.execute("SELECT * FROM miner WHERE id = %(id)s", {'id': id_f })
                for row in cursor:
                    print(row, "\n")
            except:
                print('Невалидный запрос, попробуй еще раз!\n')

#2 Выполнить запрос с несколькими соединениями (JOIN)

def get_info_by_hasrate():
    hs_f = int(input("Введите hasrate = "))
    with closing(psycopg2.connect(dbname='temp_blockchain', user='postgres',
                        password='2468', host='localhost')) as conn:
        with conn.cursor() as cursor:
            try:
                cursor.execute("select * from pool pl join miner mr on mr.id = pl.id join block bl on pl.id = bl.pool_id where hashrate > %(hs)s", {'hs': hs_f})
                for row in cursor:
                    print(row, "\n")
            except:
                print('Невалидный запрос, попробуй еще раз!\n')

#3 Выполнить запрос с ОТВ(CTE) и оконными функциями

def get_OTB():
    with closing(psycopg2.connect(dbname='temp_blockchain', user='postgres',
                        password='2468', host='localhost')) as conn:
        with conn.cursor() as cursor:
            try:
                cursor.execute("with CTE (id_client, transaction_date_client, transaction_time_client, wallet_currency_wallet) as ( select client.id, client.transaction_date, client.transaction_time, wallet.wallet_currency, cast(avg(balance) over(partition by country)  as numeric (10, 3)) as avg_balance, min(balance) over(partition by country) as min_balance, max(balance) over(partition by country) as max_balance from client join wallet on wallet.client_id = client.id ) select * from CTE")
                for row in cursor:
                    print(row, "\n")
            except:
                print('Невалидный запрос, попробуй еще раз!\n')

#4 Выполнить запрос к метаданным

def get_info_meta():
    with closing(psycopg2.connect(dbname='temp_blockchain', user='postgres',
                        password='2468', host='localhost')) as conn:
        with conn.cursor() as cursor:
            try:
                cursor.execute("select table_name as name, table_type as type from information_schema.tables where table_schema = 'public'")
                for row in cursor:
                    print(row, "\n")
            except:
                print('Невалидный запрос, попробуй еще раз!\n')

#5 Вызвать скалярную функцию (написанную в третьей лабораторной работе)

def get_func_lab_3_1():

    with closing(psycopg2.connect(dbname='temp_blockchain', user='postgres',
                        password='2468', host='localhost')) as conn:
        with conn.cursor() as cursor:
            try:
                cursor.execute("select MaxPayPerShareActivePool()")
                for row in cursor:
                    print(row, "\n")
            except:
                print('Невалидный запрос, попробуй еще раз!\n')

#6 Вызвать многооператорную или табличную функцию (написанную в третьей лабораторной работе)

def get_func_lab_3_2():
    status_f = int(input("Введите status = "))
    with closing(psycopg2.connect(dbname='temp_blockchain', user='postgres',
                        password='2468', host='localhost')) as conn:
        with conn.cursor() as cursor:
            try:
                cursor.execute("select * from  getPools(%(status)s)", {'status': status_f })
                for row in cursor:
                    print(row, "\n")
            except:
                print('Невалидный запрос, попробуй еще раз!\n')

#7 Вызвать хранимую процедуру (написанную в третьей лабораторной работе)

def get_func_lab_3_3():
    inc_f = int(input("Введите inc = "))
    start_f = int(input("Введите start id = "))
    stop_f = int(input("Введите stop id = "))
    with closing(psycopg2.connect(dbname='temp_blockchain', user='postgres',
                        password='2468', host='localhost')) as conn:
        with conn.cursor() as cursor:
            try:
                cursor.execute("drop table if exists client_copy; select * into temp client_copy from client; call increaseBalance(%(inc)s, %(start)s, %(stop)s)", {'inc': inc_f, 'start': start_f, 'stop': stop_f})
            except:
                print('Невалидный запрос, попробуй еще раз!\n')

#8 Вызвать системную функцию или процедуру

def get_func_lab_3_4():
    with closing(psycopg2.connect(dbname='temp_blockchain', user='postgres',
                        password='2468', host='localhost')) as conn:
        with conn.cursor() as cursor:
            try:
                cursor.execute('SELECT current_database()')
                for row in cursor:
                    print(row, "\n")
            except:
                print('Невалидный запрос, попробуй еще раз!\n')

#9 Создать таблицу в базе данных, соответствующую тематике БД

def get_func_lab_3_5():
    with closing(psycopg2.connect(dbname='temp_blockchain', user='postgres',
                        password='2468', host='localhost')) as conn:
        with conn.cursor() as cursor:
            try:
                cursor.execute("drop table if exists identification; create table if not exists identification (id int PRIMARY KEY NOT NULL, type varchar(256) NOT NULL); ALTER TABLE identification ADD COLUMN id_client int; ALTER TABLE identification ADD CONSTRAINT FK_id_client FOREIGN KEY(id_client) REFERENCES client(id);")
                print("OK")
            except:
                print('Невалидный запрос, попробуй еще раз!\n')

# начальная(до 20тыс в месяц) продвинутая(дешевле вывод средств + до 40тыс в месяц) максимальная(до 40тыс в месяц)

#10 Выполнить вставку данных в созданную таблицу с использованием инструкции INSERT или COPY
def get_func_lab_3_6():
    with closing(psycopg2.connect(dbname='temp_blockchain', user='postgres',
                        password='2468', host='localhost')) as conn:
        with conn.cursor() as cursor:
            try:
                cursor.execute("insert into identification values (1, '3DS identification'),(2, 'ID identification'), (3, 'offline identification')")
            except:
                print('Невалидный запрос, попробуй еще раз!\n')

if __name__ == "__main__":
    flag_create = 0
    flag_insert = 0
    print(
        "Меню:\n"
        "1.Выбрать майнера по id\n"
        "2.Информация о цепи miner-pool-block по hashrate больше введенного значения\n"
        "3.Средний,минимальный и максимальный баланс клиента\n"
        "4.Вывести имя, тип таблицы\n"
        "5.Вывести максимальную оплату активных пулов\n"
        "6.Вывести pool по статусу\n"
        "7.Увеличить баланс\n"
        "8.Имя текущей базы данных\n"
        "9.Создать таблицу\n"
        "10.Вставка данных в созданную таблицу\n"
        "0.Выход\n")

    menu = int(input("Выберите действие: "))
    while (menu != 0):
        if (menu == 1):
            get_profit_by_id_python()
        elif (menu == 2):
            get_info_by_hasrate()
        elif (menu == 3):
            get_OTB()
        elif (menu == 4):
            get_info_meta()
        elif (menu == 5):
            get_func_lab_3_1()
        elif (menu == 6):
            get_func_lab_3_2()
        elif (menu == 7):
            get_func_lab_3_3()
        elif (menu == 8):
            get_func_lab_3_4()
        elif (menu == 9):
            if (flag_create == 0):
                get_func_lab_3_5()
                flag_create = 1
            else:
                print("Таблица уже создана\n")
        elif (menu == 10):
            if flag_create == 1 and flag_insert == 0:
                get_func_lab_3_6()
            elif flag_create == 0:
                print("Таблица не создана\n")
            else:
                print("Данные уже добавлены\n")

        print(
            "Меню:\n"
            "1.Выбрать майнера по id\n"
            "2.Информация о цепи miner-pool-block по hashrate больше введенного значения\n"
            "3.Средний,минимальный и максимальный баланс клиента\n"
            "4.Вывести имя, тип таблицы\n"
            "5.Вывести максимальную оплату активных пулов\n"
            "6.Вывести pool по статусу\n"
            "7.Увеличить баланс\n"
            "8.Имя текущей базы данных\n"
            "9.Создать таблицу\n"
            "10.Вставка данных в созданную таблицу\n"
            "0.Выход\n")

        menu = int(input("Выберите из списка: "))