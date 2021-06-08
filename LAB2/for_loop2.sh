#!/bin/sh
for file in $(ls f*.sh); do
	lpr $file
done
