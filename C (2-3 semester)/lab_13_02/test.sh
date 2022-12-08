#!/bin/bash

echo -e "\ndynamic_l\n"

for ((i = 1; i <= 8; i++)) do
    ./app_dynamic_l.exe < ./tests/in_"$i".txt > out.txt
    if [[ ! -s ./tests/out_"$i".txt && ! -s out.txt ]] || cmp out.txt ./tests/out_"$i".txt &>/dev/null; then
    echo тест № "$i" пройден
    else
    echo тест № "$i" не пройден
    echo фактический результат:
    cat out.txt
    echo -e "\n"
    echo ожидаемый результат:
    cat ./tests/out_"$i".txt
    echo -e "\n"
    fi
done

echo -e "\ndynamic_d\n"

for ((i = 1; i <= 8; i++)) do
    ./app_dynamic_d.exe < ./tests/in_"$i".txt > out.txt
    if [[ ! -s ./tests/out_"$i".txt && ! -s out.txt ]] || cmp out.txt ./tests/out_"$i".txt &>/dev/null; then
    echo тест № "$i" пройден
    else
    echo тест № "$i" не пройден
    echo фактический результат:
    cat out.txt
    echo -e "\n"
    echo ожидаемый результат:
    cat ./tests/out_"$i".txt
    echo -e "\n"
    fi
done

echo -e "\nstatic\n"

for ((i = 1; i <= 8; i++)) do
    ./app_static.exe < ./tests/in_"$i".txt > out.txt
    if [[ ! -s ./tests/out_"$i".txt && ! -s out.txt ]] || cmp out.txt ./tests/out_"$i".txt &>/dev/null; then
    echo тест № "$i" пройден
    else
    echo тест № "$i" не пройден
    echo фактический результат:
    cat out.txt
    echo -e "\n"
    echo ожидаемый результат:
    cat ./tests/out_"$i".txt
    echo -e "\n"
    fi
done

echo -e "\n"

