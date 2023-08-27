#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(m);
  V<int> d(m);
  cin >> d;
  int D = accumulate(d);
  int sum = 0;
  rep(i, m) {
    sum += d[i];
    if (sum * 2 >= D) {
      wt(i + 1, D / 2 - (sum - d[i]) + 1);
      break;
    }
  }
}
