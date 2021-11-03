#!/bin/bash

g++ other.cpp -o other.out
g++ main.cpp

while true
do
echo $RANDOM $RANDOM $RANDOM $RANDOM > in
./other.out<in>out1
./a.out<in>out2
diff out1 out2
done
