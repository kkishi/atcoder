#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n, m, s);
  DisjointSet ds(n);
  VV<int> to(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  V<int> ans;
  rrep(i, n) {
    for (int j : to[i]) {
      if (j > i) ds.Union(i, j);
    }
    if (ds.Same(i, s - 1)) ans.push_back(i);
  }
  rrep(i, sz(ans)) wt(ans[i] + 1);
}
