#!/bin/bash
pi=3.14
read -p "Enter radius of circle: " radius
circlearea=$(echo "$pi * ( $radius * $radius )" | bc)
echo "Area of circle: $circlearea"

read -p "Enter length and breadth of rectangle: " len bre
rectarea=$(echo "( $len * $bre )" | bc)
echo "Area of rectangle: $rectarea"
