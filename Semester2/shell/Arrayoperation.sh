#!/bin/bash
read -p "enter the number of elements in array :" n
echo "enter the elements"
for((i=0;i<n;i++))
do
read arr[i]
done
echo "the array entered is"
echo "${arr[@]}"
sum=0
for i in "${arr[@]}"
do
sum=$((sum+i))
done
avg=$((sum/${#arr[@]}))
echo "sum of element is : $sum"
echo "Average of array elements : $avg"
largest=${arr[0]}
smallest=${arr[0]}
for i in "${arr[@]}"
do
if [ $i -gt $largest ];then
largest=$i
fi
if [ $i -lt $smallest ];then
smallest=$i
fi
done
echo "the largest element is : $largest"
echo "the smallest element is: $smallest"
read -p "enter index to remove element" index
unset arr[$index]
echo "after removing index $index: ${arr[@]}"
arr+=(110)
echo "after adding element : ${arr[@]}"

