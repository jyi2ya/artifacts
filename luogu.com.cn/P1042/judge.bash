#!/bin/bash

t=0
g++ main.cpp -o a.out
g++ others.cpp -o others.out
g++ rand.cpp -o rand.out

while true
do
./rand.out>in
./a.out<in>out1
./others.out<in>out2
echo $t
let t+=1
diff out1 out2
done
