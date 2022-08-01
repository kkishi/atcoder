#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  each(e, a)-- e;
  int ans = 0;
  int eq = 0;
  rep(i, n) {
    int x = a[i];
    if (x == i) {
      ++eq;
    } else {
      if (i < x && a[x] == i) {
        ++ans;
      }
    }
  }
  ans += eq * (eq - 1) / 2;
  wt(ans);
}
