#!/bin/sh

<<1
date=`date "+%Y-%m-%d"`
tm=`date "+%T"`
FILE_NAME="ip_mask.txt"

netstat -r | while read line
do
	#echo $line | cut -d ' ' -f1 

	line1=$(echo $line | cut -d ' ' -f1)

	line3=$(echo $line | cut -d ' ' -f3)

	IP=$(echo $line1 | grep -E '[1-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}')
	MASK=$(echo $line3 | grep -E '[1-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}')

	if [[ -n $IP && -n $MASK ]]
	then 
		echo " $date $tm $IP / $MASK " >> $FILE_NAME 
	fi

done
1



read num1

number=$(echo $num1 | grep -E '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}')
find1=$(echo $number | cut -d '.' -f 1)
find2=$(echo $number | cut -d '.' -f 2)
find3=$(echo $number | cut -d '.' -f 3)
find4=$(echo $number | cut -d '.' -f 4)
#echo "num> $number 1> $find1 2> $find2 3> $find3 4> $find4"


if [[ $find1 -le 255 ]]
then 
	if [[ $find2 -le 255 ]]
	then
		if [[ $find3 -le 255 ]]
		then
			if [[ $find4 -le 255 ]]
			then
				echo $number
				exit 0 
			else 
				echo error
				exit 1
			fi
		else 
			echo error
			exit 1
		fi
	else 
		echo error
		exit 1
	fi
else 
	echo error
	exit 1
fi
