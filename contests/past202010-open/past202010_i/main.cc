#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int tot = accumulate(all(a), int(0));
  int l = 0;
  int sum = 0;
  int ans = big;
  rep(r, n) {
    sum += a[r];
    while (sum > tot - sum) {
      chmin(ans, sum * 2 - tot);
      sum -= a[l];
      ++l;
    }
    chmin(ans, tot - sum * 2);
  }
  wt(ans);
}
