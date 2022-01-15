#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m, q);
  V<tuple<int, int, int, int>> e;
  rep(m) {
    ints(a, b, c);
    e.eb(c, a, b, -1);
  }
  rep(i, q) {
    ints(u, v, w);
    e.eb(w, u, v, i);
  }
  sort(all(e));
  DisjointSet ds(n);
  V<bool> ans(q);
  for (auto [w, a, b, i] : e) {
    --a, --b;
    if (!ds.Same(a, b)) {
      if (i != -1) {
        ans[i] = true;
      } else {
        ds.Union(a, b);
      }
    }
  }
  each(e, ans) wt(e == true);
}
