#!/bin/bash
fib_iterative(){
n=$1
a=0
b=1
if [ $n -eq 0 ];then
echo 0
return
fi
for ((i=2;i<=n;i++))
do
c=$((a+b))
a=$b
b=$c
done
echo $b
}
fib_recursive(){
n=$1
if [ $n -le 1 ];then
echo $n
else
a=$( fib_recursive $((n-1)))
b=$( fib_recursive $((n-2)))
echo $((a+b))
fi
}
read -p "enter value of n :" n
echo "fibonacci iterative method :"
fib_iterative $n
echo "fibonacci recursive method :"
fib_recursive $n
