#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int s = 0;
  int tot = accumulate(a);
  int ans = tot;
  rep(i, n) {
    s += a[i];
    chmin(ans, tot - s + (i + 1 - s));
  }
  wt(ans);
}
