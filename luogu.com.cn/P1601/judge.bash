#!/bin/bash

gcc main.cpp
cnt=0

while test $? -eq 0 && test $cnt -lt 1000000
do
let cnt+=1
echo $cnt

a=$RANDOM
b=$RANDOM
let c=a+b

echo $a > in
echo $b >> in
echo $c > out1
./a.out < in > out2
diff out1 out2

done

echo $cnt >> count
