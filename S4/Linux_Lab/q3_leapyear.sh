#!/bin/bash

read -p "Enter a year: " year

if (( $year % 4 == 0 ))
then
	if (( $year % 100 == 0 ))
	then
		if (( $year % 400 == 0 ))
		then
			echo "$year : Leap year"
		else
			echo "$year : Not leap year"
		fi
	else
		echo "$year : Leap year"
	fi
else
	echo "$year : Not leap year"
fi
