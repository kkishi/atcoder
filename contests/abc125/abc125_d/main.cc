#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int minus = 0, mini = big, sum = 0;
  rep(i, n) {
    ints(a);
    if (a < 0) {
      ++minus;
      a = -a;
    }
    sum += a;
    chmin(mini, a);
  }
  if (minus % 2 == 1) {
    sum -= mini * 2;
  }
  wt(sum);
}
