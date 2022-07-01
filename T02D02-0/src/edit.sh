#!/bin/bash

read filename
if [ ! -f "$filename" ]; then
    echo "Файл $filename не существует"
    exit 0
fi
read text
read anothertext

sed -i "" "s/${text}/${anothertext}/g" ${filename}

size=$(stat -f %z $filename)

data=$(date -r $filename "+%F %R")

shaaaaa=$(shasum -a 256 $filename | awk '{print$1}')

namefile=$(basename $filename)

echo "src/$namefile - $size - $data - $shaaaaa - sha256" >> files.log
