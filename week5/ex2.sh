#/bin/bash

if[!-f numbers]; then echo 0 > $file; fi
if ln numbers numbers.lock
then 	
	n='tail -1 numbers'
	expr $n + 1 >> numbers
	rm numbers.lock
fi
