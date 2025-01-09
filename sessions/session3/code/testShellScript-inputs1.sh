#!/bin/sh

# This script sets up CPIO 25,24,23 as inputs with pull up for Switch inputs.
# All other pins set to output 0

# looping through the GPIO numbers to set up the GPIO pin modes

# set all pins to input as this is required before setting to output
for i in 25 24 23 22 27 18 17 15 14 11 10 9
do
  echo "Setting GPIO$i to input"
  gpio -g mode $i in
done

# set all pins except switches to output 0
for i in  22 27 18 17 15 14 11 10 9
do
  echo "Setting GPIO$i to output"
  gpio -g write $i 0
done

# set the switch pins to input with a pull up resistor
for i in 25 24 23
do
  echo "Setting GPIO$i to input"
  gpio -g mode $i in
  gpio -g mode $i up
done

# now continuously print out the input states.
# loop through three switch pins to see if on or off
while :
  do
    s=""
    # looping through the gpio input numbers
    for i in 25 24 23
    do
      state=$(gpio -g read $i)
      if [ "$state" = "0" ]
       then
         s="$s GPIO $i off " 
       else 
         s="$s GPIO $i on  " 
      fi
    done
    echo $s
  done

