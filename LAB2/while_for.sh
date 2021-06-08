#!/bin/sh
foo=1

while [ "$foo" -le 16 ]
do
	echo "Hello $foo"
	foo=$(($foo+1))
done
exit 0
