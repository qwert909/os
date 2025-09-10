#!/bin/bash

echo "Enter the three numbers"
echo "enter the 1st number"
read n1
echo "enter the 2nd number"
read n2
echo "enter the 3rd number"
read n3

if (( n1 > n2 )) && (( n1 > n3 ))
 then
    echo "The greatest of the three numbers is $n1"
fi

if (( n2 > n1 )) && (( n2 > n3 ))
 then
    echo "The greatest of the three numbers is $n2"
fi

if (( n3 > n1 )) && (( n3 > n2 ))
 then
    echo "The greatest of the three numbers is $n3"
fi

if (( n1 == n2 )) && (( n2 == n3 ))
 then
    echo "All three numbers are same"
fi

