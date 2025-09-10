#!/bin/bash
echo "Enter the lower limit:"
read n1
echo "Enter the upper limit:"
read n2
echo "The prime numbers are:"
for ((i=n1; i<=n2; i++))
do
	flag=0
	for ((j=2; j<=$i/2; j++))
	do
  		if (( i%j == 0 ))
  		then
    		flag=1
    		break
  		fi  
	done

	if (( flag == 0 ))
	then
  		echo "$i"
	fi
done

