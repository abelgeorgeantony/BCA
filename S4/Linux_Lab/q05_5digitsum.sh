#!/bin/bash

num=5

while (( 9999 > $num || 99999 < $num ))
do
    clear
    read -p "Enter a 5 digit number:" num
done

sum=0

while [ $num -gt 0 ]
do
    mod=$((num % 10))    #It will split each digits
    sum=$((sum + mod))   #Add each digit to sum
    num=$((num / 10))    #divide num by 10.
done

echo $sum
