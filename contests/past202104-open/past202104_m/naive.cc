#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  ints(q);
  rep(q) {
    ints(l, r, x);
    rep(i, l - 1, r) a[i] = x;
    int ans = 0;
    rep(i, n - 1) rep(j, i + 1, n) if (a[i] == a[j])++ ans;
    wt(ans);
  }
}
