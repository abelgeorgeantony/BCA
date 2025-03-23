#!/bin/bash

read -p "Enter the name of file: " fname
echo "Enter 5 values in the file $fname and press ^d at the end:"

cat > $fname

sort $fname > sortedfile

echo "Unsorted File:"
cat $fname
echo "Sorted File:"
cat sortedfile
