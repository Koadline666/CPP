#!/bin/bash
x=1
y=0
t=1000
while [ true ]
do
	A=$(./ex02 | grep A| wc -l)
	if [ $A -gt 0 ]
	then
		y=$((y+1))
	fi
	x=$((x+1))
A=$(((y * 100)/x))
echo "it found A " $A "% of the time"

done