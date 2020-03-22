#!/bin/bash

i=0
sum=0
exec 0<numbers.txt 
while read var
do
sum=$(($sum + $var))
i=$(($i+1))
done
sum=$(($sum/$i))
echo "Среднее арифметичское: $sum"
echo "Количество входных аргументов: $i"



