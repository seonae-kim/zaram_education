#!/bin/sh


echo "input N"
read N

echo "$N numbers"
 
read -a num

for i in ${num[*]}
do 
	echo -n "$(( $i * 2 )) "
done
