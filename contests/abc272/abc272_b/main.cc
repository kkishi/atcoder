#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  set<pair<int, int>> st;
  rep(i, m) {
    ints(k);
    rep(k) {
      ints(x);
      --x;
      st.insert({i, x});
    }
  }
  bool ok = true;
  rep(i, n) rep(j, i) {
    bool ok2 = false;
    rep(k, m) if (st.count({k, i}) && st.count({k, j})) ok2 = true;
    if (!ok2) ok = false;
  }
  wt(ok);
}
