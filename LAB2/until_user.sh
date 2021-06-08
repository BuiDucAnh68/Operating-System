#!/bin/sh
echo "Locate for user ..."
until who|grep "$1" > /dev/null
do 
	sleep 60
done
echo -e\\a
echo "***** $1 has just logged in *****"
exit 0
