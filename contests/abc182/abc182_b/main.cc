#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  int maxi = 0;
  rep(k, 2, 1001) {
    int x = 0;
    rep(i, n) if (a[i] % k == 0)++ x;
    if (chmax(maxi, x)) ans = k;
  }
  wt(ans);
}
