#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector<int> x(n);
  cin >> x;
  int ans = big;
  rep(i, k - 1, n) {
    int l = x[i - (k - 1)], h = x[i];
    chmin(ans, h - l + min(abs(h), abs(l)));
  }
  wt(ans);
}
