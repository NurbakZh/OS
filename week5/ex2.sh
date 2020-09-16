#/bin/bash

counter=0
while [ $counter -le 49 ] 
do
	if ln file.txt file.lock; then
		number=$(tail -1 file.txt | grep -Eo '[0-9]+$')
		number=$(($number + 1))
		echo $number >> file.txt 
		rm file.lock
	else
		echo nononono_cant_add_this_number
		counter=$(($counter-1))
	fi
	counter=$(($counter+1))
done
