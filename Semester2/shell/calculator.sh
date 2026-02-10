#!/bin/bash
while true
do
echo "--------------------------------"
echo "-------calculator--menu---------"
echo "   1. Addition                  "
echo "   2. Subtraction               "
echo "   3. Multiplication            "
echo "   4. Division                  "
echo "   5. Exit                      "
echo "------Enter Your Choice --------"
read ch
read -p "enter first num " num1
read -p "enter second num " num2
case $ch in 
1)echo "result=$((num1 + num2))";;
2)echo "result=$((num1 - num2))";;
3)echo "result=$((num1 * num2))";;
4)echo "result=$((num1 / num2))";;
5)echo "----exiting-------"
exit 1;;
esac
done
