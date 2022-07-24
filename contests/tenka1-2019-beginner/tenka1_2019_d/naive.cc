#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int sa = accumulate(a);
  int p = 1;
  rep(n) p *= 3;
  int large = 0;
  int equal = 0;
  int other = 0;
  int ok = 0;
  rep(mask, p) {
    int x = mask;
    V<int> sum(3);
    rep(i, n) {
      sum[x % 3] += a[i];
      x /= 3;
    }
    sort(sum);
    if (sum[2] * 2 > sa) {
      ++large;
    } else if (sum[1] * 2 == sa && sum[2] * 2 == sa) {
      ++equal;
    } else {
      if (sum[1] - sum[0] <= sum[2] && sum[2] < sum[0] + sum[1]) {
        ++ok;
      }
      ++other;
    }
  }
  dbg(large, equal, other, ok);
  wt(ok);
}
