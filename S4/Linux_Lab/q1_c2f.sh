#!/bin/bash
read -p "Enter degree celsius temperature: " C
F=$(echo "1.8 * $C + 32" | bc)				
echo "The temperature in Fahrenheit is $F"
