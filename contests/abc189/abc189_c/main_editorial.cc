#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = -big;
  rep(i, n) {
    int x = a[i];
    rep(j, i, n) {
      chmin(x, a[j]);
      chmax(ans, (j - i + 1) * x);
    }
  }
  wt(ans);
}
