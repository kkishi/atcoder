#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n), c(n);
  cin >> a >> b >> c;
  map<int, int> acnt;
  each(e, a)++ acnt[e];
  int ans = 0;
  rep(i, n) ans += acnt[b[c[i] - 1]];
  wt(ans);
}
