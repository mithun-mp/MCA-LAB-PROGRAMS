#!/bin/bash
echo "-----Logical Operation -----"
echo "Enter the First Operand(true/false)"
read n1
echo "Enter the Second Operand(true/false)"
read n2
if [ $n1 = "true" ] || [ $n2 = "true" ]
then echo "Logical OR True"
else echo "Logical OR False"
fi
if [ $n1 = "true" ] && [ $n2 = "true" ]
then echo "Logical AND True"
else echo "Logical AND False"
fi
echo "logical NOT for First operand "
if [ $n1 = "true" ]
then echo "False"
else echo "True"
fi
echo "logical NOT for Second operand "
if [ $n2 = "true" ]
then echo "False"
else echo "True"
fi
