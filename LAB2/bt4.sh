#!/bin/sh
#bt4.sh

echo "Nhap chuoi ban can tim"
read string_read

if grep $string_read 123.txt ;then 
	echo "Chuoi ton tai"
fi
if grep !$string_read 123.txt;then
	echo "Chuoi  khong ton tai"
fi
exit 0 

