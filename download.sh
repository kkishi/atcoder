#!/bin/bash

set -e

# e.g., abc160
contest="$1"

if [[ $contest = '' ]]; then
  echo "contest not specified";
  exit 1;
fi

if [[ ! -d $contest ]]; then
  mkdir $contest;
fi

cd $contest

for problem in a b c d e f; do
  if [[ ! -d $problem ]]; then
    mkdir $problem;
    cd $problem;
    cp ../../template.cc main.cc
    oj d "https://atcoder.jp/contests/${contest}/tasks/${contest}_${problem}";
    cd ../
  fi
done
