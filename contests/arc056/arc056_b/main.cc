#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "graph.h"

void Main() {
  ints(n, m, s);
  DisjointSet ds(n);
  Graph to(n);
  to.Read(m);
  V<int> ans;
  rrep(i, n) {
    for (int j : to[i]) {
      if (j > i) ds.Union(i, j);
    }
    if (ds.Same(i, s - 1)) ans.pb(i);
  }
  rrep(i, sz(ans)) wt(ans[i] + 1);
}
