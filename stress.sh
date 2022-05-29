#!/bin/bash

set -e

clear=0

while test $# -gt 1; do
  case "$1" in
    -clear)
      shift
      clear=1
  esac
done

cd $1

if [[ $clear = 1 ]]; then
  rm -f test/random-*
fi

atcoder -o gen gen.cc
oj generate-input ./gen

atcoder -o naive naive.cc
oj generate-output -c ./naive
