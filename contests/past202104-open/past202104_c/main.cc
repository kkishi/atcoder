#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> a(n);
  rep(i, n) {
    ints(k);
    a[i].resize(k);
    cin >> a[i];
  }
  ints(p, q);
  V<int> b(p);
  cin >> b;
  int ans = 0;
  rep(i, n) {
    int s = 0;
    each(e1, a[i]) each(e2, b) if (e1 == e2)++ s;
    if (s >= q) ++ans;
  }
  wt(ans);
}
