#!/bin/bash

echo "Enter 1st number"
read n1
echo "Enter 2nd number"
read n2
echo "Enter 3rd number"
read n3

if [ $n1 -ge $n2 ] && [ $n1 -ge $n3 ];then
	echo "$n1 is greatest"
elif [ $n2 -ge $n1 ] && [ $n2 -ge $n3 ];then
	echo "$n2 is greatest"
else
	echo "$n3 is greatest"
fi
