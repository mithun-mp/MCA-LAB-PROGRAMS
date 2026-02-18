#!/bin/bash
flag=0
while [ flag==0 ]
do
read -p "enter the password " pass
if [[ ${#pass} -lt 8 ]];then
echo "enter atleast 8 character length"
continue
fi
if [[ ! $pass =~ [A-Z] ]];then
echo "use atleast one UPPER CASE"
continue
fi
if [[ ! $pass  =~ [a-z] ]];then
echo "use atleast one LOWER CASE"
continue
fi
if [[ ! $pass =~ [0-9] ]];then
echo "use atleast one digit"
continue
fi
if [[ ! $pass =~ [^a-zA-Z0-9] ]];then
echo "use special characters "
continue
else
echo " Valid password"
flag=1
exit
fi
done


