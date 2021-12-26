#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  each(e, p)-- e;
  ints(m);
  VV<pair<int, int>> g(n);
  DisjointSet ds(n);
  rep(i, m) {
    ints(a, b);
    --a, --b;
    if (!ds.Same(a, b)) {
      ds.Union(a, b);
      g[a].eb(b, i);
      g[b].eb(a, i);
    }
  }

  V<int> ans;
  rep(i, n) if (i != p[i]) {
    Fix([&](auto rec, int node, int parent) -> void {
      each(child, _, g[node]) if (child != parent) rec(child, node);
      int NODE = node;
      if (!Fix([&](auto rec, int node, int parent) -> bool {
            if (p[node] == NODE) return true;
            each(child, i, g[node]) if (child != parent && rec(child, node)) {
              ans.pb(i + 1);
              swap(p[node], p[child]);
              return true;
            }
            return false;
          })(node, -1)) {
        wt(-1);
        exit(0);
      }
    })(i, -1);
  }
  wt(sz(ans));
  wt(ans);
}
