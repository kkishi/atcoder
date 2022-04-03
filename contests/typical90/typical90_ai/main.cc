#include <bits/stdc++.h>

#include "atcoder.h"
#include "dfs_order.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(n);
  Graph g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].eb(b);
    g[b].eb(a);
  }
  ints(q);
  set<int> ks;
  VV<int> qs(q);
  rep(i, q) {
    ints(k);
    ks.insert(k);
    rep(k) {
      ints(v);
      qs[i].pb(v - 1);
    }
  }
  if (n <= 5000 && q <= 5000) {
    each(e, qs) {
      V<bool> st(n);
      each(E, e) st[E] = true;
      Fix([&](auto rec, int node, int parent) -> bool {
        bool ret = false;
        if (st[node]) ret = true;
        each(to, g[node]) {
          if (to == parent) continue;
          if (rec(to, node)) ret = true;
        }
        if (ret) st[node] = true;
        return ret;
      })(e[0], -1);
      wt(count(all(st), true) - 1);
    }
  } else if (ks == set<int>{2}) {
    RootedTree t(g);
    each(e, qs) wt(t.Distance(e[0], e[1]));
  } else if (ks == set<int>{3}) {
    RootedTree t(g);
    each(e, qs) {
      int s = 0;
      rep(i, 3) s += t.Distance(e[i], e[(i + 1) % 3]);
      wt(s / 2);
    }
  } else {
    RootedTree t(g);
    V<int> o = DFSOrder(g);
    V<int> ro(n);
    rep(i, n) ro[o[i]] = i;
    each(e, qs) {
      int n = sz(e);
      int s = 0;
      sort(e, [&](int i, int j) { return ro[i] < ro[j]; });
      rep(i, n) s += t.Distance(e[i], e[(i + 1) % n]);
      wt(s / 2);
    }
  }
}
