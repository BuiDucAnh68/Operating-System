#!/bin/sh
echo "Is it morning?Please answer yes or no"
read timeofday

case "$timeofday" in
	"yes") echo "Good Morning";;
	"no") echo "Good afternoon";;
	"y") echo "Good MORNING";;
	"n") echo "Good AFTERNOON";;
	*) echo "Sorry,answer not recognised";;
esac
exit 0
