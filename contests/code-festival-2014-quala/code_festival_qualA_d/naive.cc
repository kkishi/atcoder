#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, k);
  int ans = numeric_limits<int>::max();
  rep(i, 1, 10000000) {
    if (abs(a - i) > ans) continue;
    V<bool> u(10);
    int j = i;
    while (j) {
      u[j % 10] = true;
      j /= 10;
    }
    if (count(all(u), true) <= k) chmin(ans, abs(a - i));
  }
  wt(ans);
}
