#!/bin/sh
# looping through the gpio numbers to set up the GPIO pin states
# NOTE GP21 on the gertboard is actually GPIO (BCM) 27
for i in 22 27 18 17 15 14 11 10 9
do
  echo "Setting GPIO$i to input"
  gpio -g mode $i in
done
for i in 22 27 18 17 15 14 11 10 9
do
  echo "Setting GPIO$i to output"
  gpio -g mode $i out
  gpio -g write $i 0 
done

while :
  do
    # looping through the gpio numbers
    for i in 22 27 18 17 15 14 11 10 9
    do
      echo "Toggling GPIO$i output"
      sleep .1
      gpio -g write $i 1
      sleep .1
      gpio -g write $i 0 
    done
  done
