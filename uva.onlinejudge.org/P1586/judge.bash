#!/bin/bash

gcc rand.c -o rand.out
g++ main.cpp -o a.out
g++ other.cpp -o other.out
g++ other2.cpp -o other2.out -std=c++11

a=1

while test $? -eq 0
do
let a+=1
echo "data:$a" > count
./rand.out > in
./a.out<in>out1
./other2.out<in>out2
diff out1 out2 > diff
done
