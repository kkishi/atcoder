#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<set<int>> es(n);
  int ans = n;
  rep(q) {
    ints(tp);
    if (tp == 1) {
      ints(u, v);
      --u, --v;
      if (es[u].empty()) --ans;
      es[u].insert(v);
      if (es[v].empty()) --ans;
      es[v].insert(u);
    } else {
      ints(v);
      --v;
      if (!es[v].empty()) {
        ++ans;
        each(e, es[v]) {
          if (sz(es[e]) == 1) ++ans;
          es[e].erase(v);
        }
        es[v].clear();
      }
    }
    wt(ans);
  }
}
