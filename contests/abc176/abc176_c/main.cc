#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int maxi = 0;
  int ans = 0;
  rep(i, n) {
    ans += max(0LL, maxi - a[i]);
    chmax(maxi, a[i]);
  }
  wt(ans);
}
