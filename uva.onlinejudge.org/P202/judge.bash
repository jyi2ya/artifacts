#!/bin/sh

gcc -DDEBUG -Wall main.cpp
gcc -DDEBUG -Wall -o other.out other.cpp
gcc r.c -o r.out

cnt=1

while true
do
echo $cnt
./r.out>in
./a.exe<in>out1
./other.out<in>out2

diff out1 out2
if test $? -ne 0
then 
break
fi

let cnt+=1
done

echo ERROR
