#!/bin/bash

for ((i = 1; i <= 10; i++)) do
    ./app.exe < ./tests/in_"$i".txt > out.txt
    if cmp -s out.txt ./tests/out_"$i".txt; then
    echo тест № "$i" пройден
    else
    echo тест № "$i" не пройден
    echo фактический результат:
    cat out.txt
    echo ожидаемый результат:
    cat ./tests/out_"$i".txt
    echo -e "\n"
    fi
done
