#!/bin/bash

echo "Enter Register Number:"
read regno

echo "Enter Student Name:"
read name

echo "Enter marks for 5 subjects:"

read -p "Subject 1: " m1
read -p "Subject 2: " m2
read -p "Subject 3: " m3
read -p "Subject 4: " m4
read -p "Subject 5: " m5

total=$((m1 + m2 + m3 + m4 + m5))
percentage=$((total / 5))

# Grade calculation
if [ $percentage -ge 90 ]; then
    grade="A+"
elif [ $percentage -ge 75 ]; then
    grade="A"
elif [ $percentage -ge 60 ]; then
    grade="B"
elif [ $percentage -ge 50 ]; then
    grade="C"
else
    grade="F"
fi

echo "---------------------------"
echo "        MARK LIST          "
echo "---------------------------"
echo "Register No : $regno"
echo "Name        : $name"
echo "---------------------------"
echo "Subject1: $m1"
echo "Subject2: $m2"
echo "Subject3: $m3"
echo "Subject4: $m4"
echo "Subject5: $m5"
echo "---------------------------"
echo "Total      : $total"
echo "Percentage : $percentage%"
echo "Grade      : $grade"
echo "---------------------------"