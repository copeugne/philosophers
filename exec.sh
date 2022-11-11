#!/bin/bash
make
x=0
while [ $x -le 1500 ]
do
  printf "$x "
  sh random_gen.sh 5 | xargs ./push_swap
  printf "\n\n\n"
  x=$(( $x + 1 ))
  sleep 0.15
done
