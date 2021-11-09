#!/bin/bash

let cnt=1

while true 
do
echo 5 5 > in
echo $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM>>in
echo $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM>>in
echo $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM>>in
echo $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM>>in
echo $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM>>in

./main.out<in>out1
./int128.out <in>out2

echo -n $cnt ':'
cat out1
let cnt+=1

diff out1 out2

if test $? -ne 0
then
break
fi

done
