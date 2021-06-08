#!/bin/sh
sum=0
i=0

echo "Nhap gia tri n:"
read n

if [ "$n" -lt 10 ];then
echo "Gia tri cua n phai lon hon hoac bang 10"

else

while [ "$i" -le "$n" ]
do
	sum=$(($sum + $i))
	i=$(($i+1))
done

fi

echo "tong la:$sum"

exit 0
