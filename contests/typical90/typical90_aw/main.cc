#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> v;
  rep(m) {
    ints(c, l, r);
    v.eb(c, l - 1, r);
  }
  sort(all(v));
  DisjointSet ds(n + 1);
  int ans = 0;
  for (auto [c, i, j] : v) {
    if (!ds.Same(i, j)) {
      ds.Union(i, j);
      ans += c;
    }
  }
  if (ds.Size(0) < n + 1) ans = -1;
  wt(ans);
}
