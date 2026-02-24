#!/bin/bash
flag=1
while [ $flag!=0 ]
do
echo ""
echo "1.Binary to decimal "
echo "2.Decimal to Binary "
echo "3.Exit"
read -p "Enter your choice :" ch
case $ch in
1)read -p "enter the binary number :" bin
dec=0
base=1
while [ $bin -gt 0 ]
do
rem=$((bin%10))
dec=$((dec+rem*base))
base=$((base*2))
bin=$((bin/10))
done
echo ""
echo "decimal : $dec ";;
2)read -p "enter the decimal number :" dec
bin=""
while [ $dec -gt 0 ]
do
rem=$((dec%2))
bin="$rem$bin"
dec=$((dec/2))
done
echo ""
echo "Binary equivalent : $bin";;
3)echo "exiting"
flag=0
exit;;
*)echo "invalid choice";;
esac
done
