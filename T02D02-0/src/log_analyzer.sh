#!/bin/bash

str=$(wc -l $1 | awk '{print$1}')

file=$( cat $1 |  awk '{print$1}' | uniq | wc -l)

shaaa=$( cat $1 | awk '{print$8}' | uniq | wc -l )
strr=$(echo "$str" | tr -d '[:space:]')
filee=$(echo "$file" | tr -d '[:space:]')
shaa=$(echo "$shaaa" | tr -d '[:space:]')
echo "$strr $filee $shaa" 
