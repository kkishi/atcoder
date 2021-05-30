#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  map<int, V<int>> vs;
  rep(i, m) {
    ints(x, y);
    vs[x].pb(y);
  }
  set<int> st;
  st.insert(n);
  each(x, v, vs) {
    V<int> add;
    each(y, v) if (st.count(y - 1) || st.count(y + 1)) add.pb(y);
    each(y, v) st.erase(y);
    each(e, add) st.insert(e);
  }
  wt(sz(st));
}
