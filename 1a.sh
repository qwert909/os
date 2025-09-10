#!/bin/bash

echo "Enter the number: "
read num1

num2=`echo $num1 | rev`

if [[ $num1 == $num2 ]]
then
	echo "It is a Palindrome"
else
	echo "It is not a palindrome"
fi
