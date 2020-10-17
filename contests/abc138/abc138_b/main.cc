#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  double sum = 0;
  rep(i, n) {
    rd(double, a);
    sum += 1 / a;
  }
  wt(1 / sum);
}
