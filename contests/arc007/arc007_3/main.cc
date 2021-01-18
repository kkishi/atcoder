#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(c);
  int n = sz(c);
  int ans = big;
  rep(s, 1 << n) {
    V<bool> v(n);
    rep(i, n) if (hasbit(s, i)) rep(j, n) if (c[j] == 'o') v[(i + j) % n] =
        true;
    if (find(all(v), false) == v.end()) chmin(ans, popcount(s));
  }
  wt(ans);
}
