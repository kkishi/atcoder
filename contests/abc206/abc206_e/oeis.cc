// Code used to find some OEIS entries.
#include <bits/stdc++.h>

#include "atcoder.h"

int Naive(int l, int r) {
  int ans = 0;
  rep(x, l, r + 1) {
    rep(y, x + 1, r + 1) {
      int g = gcd(x, y);
      if (g != 1 && x / g != 1 && y / g != 1) ++ans;
    }
  }
  return ans * 2;
}

void Main() {
  ints(l, r);
  wt(Naive(l, r));
  V<int> v;
  rep(i, 1, 20) { v.pb(Naive(1, i) / 2); }
  dbg(v);
  V<int> dv;
  rep(i, sz(v) - 1) dv.pb(v[i + 1] - v[i]);
  dbg(dv);
}
