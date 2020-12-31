#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, t);
  V<int> a(n);
  cin >> a;
  int n1 = n / 2;
  int n2 = n - n1;
  V<int> x;
  rep(s, 1 << n1) {
    int xi = 0;
    rep(i, n1) if (hasbit(s, i)) xi += a[i];
    x.push_back(xi);
  }
  sort(all(x));
  V<int> y;
  rep(s, 1 << n2) {
    int yi = 0;
    rep(i, n2) if (hasbit(s, i)) yi += a[i + n1];
    y.push_back(yi);
  }
  sort(all(y));
  int ans = 0;
  rep(i, sz(x)) {
    auto it = lower_bound(all(y), t - x[i] + 1);
    if (it == y.begin()) continue;
    --it;
    chmax(ans, x[i] + *it);
  }
  wt(ans);
}
