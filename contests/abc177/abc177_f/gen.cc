#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  int h = 100, w = 100;
  wt(h, w);

  random_device device;
  mt19937 generator(device());
  uniform_int_distribution<int> distribution(1, w);

  rep(i, h) {
    int a = distribution(generator), b = distribution(generator);
    if (a > b) swap(a, b);
    wt(a, b);
  }
}
