#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> x(n);
  cin >> x;
  VV<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  VV<int> top(n);
  Fix([&](auto rec, int node, int parent) -> V<int> {
    V<int>& t = top[node];
    t = {x[node]};
    each(child, g[node]) if (child != parent) {
      each(e, rec(child, node)) t.pb(e);
    }
    sort(all(t), greater{});
    while (sz(t) > 20) t.pop_back();
    return t;
  })(0, -1);
  rep(q) {
    ints(v, k);
    wt(top[v - 1][k - 1]);
  }
}
