#!/bin/bash
x=1
y=0
t=1000
while [ true ]
do
	res=$(./ex02 | grep failed | wc -l)
	if [ $res -gt 0 ]
	then
		y=$((y+1))
	fi
	x=$((x+1))
res=$(((y * 100)/x))
echo "it failed " $res "% of the time"
done