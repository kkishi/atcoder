#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);

  int total = 0;
  V<int> inc(m + 1);
  rep(i, n) {
    ints(l, r, s);
    total += s;
    inc[l - 1] += s;
    inc[r] -= s;
  }
  int sum = 0;
  int mini = big;
  rep(i, m) {
    sum += inc[i];
    chmin(mini, sum);
  }
  wt(total - mini);
}
