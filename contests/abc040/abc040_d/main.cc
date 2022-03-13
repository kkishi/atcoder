#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  V<tuple<int, bool, int, int>> e;
  rep(m) {
    ints(a, b, y);
    e.eb(y, false, a, b);
  }
  ints(q);
  rep(i, q) {
    ints(v, w);
    e.eb(w, true, v, i);
  }
  sort(e, greater{});
  DisjointSet ds(n);
  V<int> ans(q);
  for (auto [y, query, a, b] : e) {
    if (query) {
      ans[b] = ds.Size(a - 1);
    } else {
      ds.Union(a - 1, b - 1);
    }
  }
  rep(i, q) wt(ans[i]);
}
