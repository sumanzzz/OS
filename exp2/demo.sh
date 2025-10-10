#!/bin/bash

read -p"Enter first number" a
read -p"Enter first number" b
read -p"Enter first number" c

if [ $a -ge $b ] && [ "$a" -ge "$c" ]; then
	echo "$a is greatest"
	
elif [ "$b" -ge "$a" ] && [ "$b" -ge "$c" ]; then
	echo "$b is greatest"
	
else
	echo "$c is greatest"
fi
if [ "$a" -le "$b" ] && [ "$a" -le "$c" ]; then
	echo "$a is smallest"
	
elif [ "$b" -le "$a" ] && [ "$b" -le "$c" ]; then
	echo "$b is smallest"
	
else
	echo "$c is smallest"
fi









