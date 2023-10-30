#!/bin/sh

<< END
echo "input N"
read num 

i=1
while [ $i -le $num ]
do 
	j=1
	p=`expr $num - $i + 1`
	
	while [ $j -le $num ]
	do
		if [ $j -lt $p ]
		then
			echo -n " "
		else 
			echo -n "*"
		fi
	j=`expr $j + 1`
	done

	echo ""
	
i=`expr $i + 1`
	
done

exit 0

END


echo "input N"
read num

i=1
while [ $i -le $num ]
do
	j=1 
	k=`expr $num - $i + 1`
	while [ $j -le $k ]
	do
		echo -n "*"
		j=`expr $j + 1`
	done

	i=`expr $i + 1`
	echo ""
	
done



