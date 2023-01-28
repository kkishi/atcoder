#include <bits/stdc++.h>

#include "atcoder.h"
#include "rolling_hash_cumulative_sum.h"

void Main() {
  ints(n);
  strings(t);
  string T = t;
  reverse(T);
  RollingHashCumulativeSum th(t), Th(T);
  rep(i, n + 1) {
    // s  = t[0, i) + t[i + n, 2n)
    // s' = rev(t[i, i + n))
    //    = T[n - i, 2n - i)
    //    = T[n - i, n) + T[n, 2n - i)
    if (th.Hash(0, i) == Th.Hash(n - i, n) &&
        th.Hash(i + n, 2 * n) == Th.Hash(n, 2 * n - i)) {
      wt(t.substr(0, i) + t.substr(i + n));
      wt(i);
      return;
    }
  }
  wt(-1);
}
