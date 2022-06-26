#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  V<bool> open(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    if (u == -1) {
      open[v] = true;
    } else {
      g[u].eb(v, 1);
      g[v].eb(u, 1);
    }
  }
  auto f = [&g](int s) {
    V<int> w;
    each(e, Dijkstra(g, s).dist) w.eb(e ? *e : big);
    return w;
  };
  V<int> s = f(0), t = f(n - 1);
  int su = big, tu = big;
  rep(i, n) if (open[i]) {
    chmin(su, s[i]);
    chmin(tu, t[i]);
  }
  V<int> ans;
  rep(i, n) {
    int x = min(s[n - 1],                // Do not use i
                min(s[i], su + 1) +      // Min from 1 to i
                    min(t[i], tu + 1));  // Min from i to n
    ans.eb(x == big ? -1 : x);
  }
  wt(ans);
}
