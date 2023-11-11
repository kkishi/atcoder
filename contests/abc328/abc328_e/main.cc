#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m, k);
  V<tuple<int, int, int>> e;
  rep(m) {
    ints(u, v, w);
    e.eb(u-1, v-1, w);
  }
  vector<int> use(m);
  rep(i, n-1) use[m - 1 - i] = 1;
  int ans = big;
  do {
    DisjointSet ds(n);
    bool ok = true;
    int sum = 0;
    rep(i, m) if (use[i]) {
      auto [u, v, w] = e[i];
      if (ds.Same(u, v)) ok = false;
      ds.Union(u, v);
      sum += w;
    }
    if (ok) chmin(ans, sum % k);
  } while (next_permutation(all(use)));
  wt(ans);
}
