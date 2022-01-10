#!/bin/sh
#
# Script that uses SimplifyNewick to simplify a Newick
#
# Usage:
#
# ./demo.sh
#
# Assumes that the 'SimplifyNewickDesktop' binary is in the current working folder,
#

my_newick="((((((((((((10,10),10),10),10),10),10),10),10),10),10),10),10)"
million=1000000
one_hundred_million=100000000
number=$million

# Write first result to file
./SimplifyNewickDesktop $my_newick $number > out.txt

number=$((number + million))
while [ $number -lt $one_hundred_million ]; do
  echo "Number = $number"
  number=$((number + million))
  #Append other results to file
  ./SimplifyNewickDesktop $my_newick $number >> out.txt
done
