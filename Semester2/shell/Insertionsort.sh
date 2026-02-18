#!/bin/bash
read -p "enter the number of elements in array :" n
echo "enter the elements"
for((i=0;i<n;i++))
do
read arr[$i]
done
echo "the array entered is"
echo "${arr[@]}"
for((i=1;i<n;i++))
	do
	key=${arr[$i]}
	j=$((i-1))
	while [ $j -ge 0 ] && [ ${arr[$j]} -lt $key ]
		do
			arr[$((j+1))]=${arr[$j]}
		j=$((j-1))
		done
	arr[$((j+1))]=$key
	done
echo "the sorted array is"
echo "${arr[@]}"
