#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, q);
  V<int> x(n);
  cin >> x;
  Graph g(n);
  g.Read();
  VV<int> top(n);
  Fix([&](auto rec, int node, int parent) -> V<int> {
    V<int>& t = top[node];
    t = {x[node]};
    each(child, g[node]) if (child != parent) {
      each(e, rec(child, node)) t.pb(e);
    }
    sort(t, greater{});
    while (sz(t) > 20) t.pop_back();
    return t;
  })(0, -1);
  rep(q) {
    ints(v, k);
    wt(top[v - 1][k - 1]);
  }
}
