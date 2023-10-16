#!/bin/bash

for ((i = 1; i < 9; i++))
do
./app.exe < in_"$i".txt > out.txt
if cmp -s out.txt out_"$i".txt; then
 echo тест № "$i" пройден
else
 echo тест № "$i" не пройден
 cat out.txt
fi
done

#for file in *
#do
#if [ -f "$file.txt" ]
#then
#echo "$file is a file"
#fi
#done

#./app.exe < in_1.txt > out.txt
#cmp -s out.txt out_1.txt && echo Равны
