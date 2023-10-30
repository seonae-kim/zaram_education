#!/bin/sh

add()
{
	result=`expr $1 + $2`
	echo add = $result	
}

sub()
{
	result=`expr $1 - $2`
	echo sub = $result
}

mul()
{
	result=`expr $1 \* $2`
	echo mul = $result
}

div()
{
	result=$(echo "scale=2; $1 / $2" | bc)

	echo div = $result
}

num1=$1
num2=$3
op=$2

if [[ $num1 -eq 0 ]]
	then read num1 op num2
	fi

if [[ $op == "+" ]]
then 
	add $num1 $num2

elif [[ $op == "-" ]]
then
	sub $num1 $num2

elif [[ $op == "*" ]]
then 
	mul $num1 $num2

elif [[ $op == "/" ]]
then 
	div $num1 $num2
else
	echo "error"

fi
	



