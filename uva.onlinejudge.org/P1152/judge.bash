#!/bin/bash

gcc data.c -o data
gcc main.c -o a
gcc force.c -o force

cnt=1
maxtest=10

while test $cnt -lt $maxtest
do
	./data $RANDOM > in
	./a < in > out_a
	./force < in > out_force
	echo -n "testdata $cnt:`cat out_a` " | tr '\n' ' '
	cat out_force
	diff out_a out_force
	if [ $? -ne 0 ] ; then
		break;
	fi
	let cnt+=1
done

rm data.exe
rm a.exe
rm force.exe
rm in
rm out_a
rm out_force
