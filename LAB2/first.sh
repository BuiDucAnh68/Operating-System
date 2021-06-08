#!/bin/sh
#first.sh
for file in  *
do
if grep -l 'main()' $file
	then
		more $file
	fi
done
exit 0
