#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "modint.h"
#include "strongly_connected_component.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> f(n);
  cin >> f;
  each(e, f)-- e;

  Graph g(n);
  rep(i, n) g[i].eb(f[i]);
  VV<int> scc = StronglyConnectedComponents(g);
  int x = 0;
  each(e, scc) {
    set<int> st(all(e));
    bool ok = true;
    each(i, e) if (!st.count(f[i])) ok = false;
    if (ok) ++x;
  }
  wt(mint(2).Pow(x) - 1);
}
