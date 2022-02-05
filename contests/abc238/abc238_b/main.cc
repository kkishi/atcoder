#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<bool> b(360);
  b[0] = true;
  int x = 0;
  each(e, a) {
    x += e;
    x %= 360;
    b[x] = true;
  }
  V<int> c;
  rep(i, 360) if (b[i]) c.pb(i);
  int ans = -big;
  rep(i, sz(c)) chmax(ans, (360 + c[(i + 1) % sz(c)] - c[i]) % 360);
  wt(ans);
}
