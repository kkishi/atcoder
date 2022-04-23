#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n) rep(j, n) rep(k, n) {
    if (a[i] == a[j] * a[k]) {
      dbg(i, j, k);
      ++ans;
    }
  }
  wt(ans);
}
