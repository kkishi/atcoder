#!/bin/bash
# Usage:
# $ ./eval.sh main_change_swap.cc

set -e
g++ -O2 -DDEBUG $1

tmpdir=`mktemp -d -p $PWD`
echo $tmpdir
cd $tmpdir

for seed in `seq 20`; do
  ../tester/generator.py $seed > in;
  ../a.out < in > out;
  ../tester/tester.py in out >> result;
  tail -n 2 result;
done

cat result | grep score | sed 's/score: //' | awk -F'|' '{sum+=$NF} END {print sum}'

cd ../
rm -rf $tmpdir
