#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  DisjointSet ds(n);
  V<tuple<int, int, int>> vec;
  rep(n - 1) {
    ints(u, v, w);
    vec.eb(w, u - 1, v - 1);
  }
  sort(vec);
  int ans = 0;
  for (auto [w, u, v] : vec) {
    ans += ds.Size(u) * ds.Size(v) * w;
    ds.Union(u, v);
  }
  wt(ans);
}
