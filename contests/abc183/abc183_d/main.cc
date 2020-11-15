#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, w);
  V<pair<int, int>> inc;
  rep(n) {
    ints(s, t, p);
    inc.emplace_back(s, p);
    inc.emplace_back(t, -p);
  }
  sort(all(inc));
  int der = 0;
  bool ok = true;
  rep(i, sz(inc)) {
    auto [t0, d0] = inc[i];
    auto [t1, d1] = inc[i + 1];
    der += d0;
    if (t1 - t0 > 0 && der > w) ok = false;
  }
  wt(ok);
}
