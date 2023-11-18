#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> c(n);
  cin >> c;
  V<set<int>> st(n);
  rep(i, n) st[i].insert(c[i]);
  rep(q) {
    ints(a, b);
    --a, --b;
    if (sz(st[a]) > sz(st[b])) {
      each(e, st[b]) st[a].insert(e);
      swap(st[a], st[b]);
    } else {
      each(e, st[a]) st[b].insert(e);
    }
    st[a].clear();
    wt(sz(st[b]));
  }
}
