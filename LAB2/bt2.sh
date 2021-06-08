#!/bin/sh

echo "Hay nhap ten cua ban: "
read name

echo "Hay nhap MSSV: "
read ID

while [ "$ID" != "19521190" ]; do
echo "MSSV cua ban nhap khong dung xin vui long nhap lai"
read ID

echo "Ten: $name"
echo "MSSV: $ID"
done
exit 0

