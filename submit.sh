#!/bin/bash

set -e

file=$1
g++ -O2 -std=c++17 -DDEBUG $file
oj t -t 2 --mle 1024
oj submit -y --no-open $file
