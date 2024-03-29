#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m, r, t);
  WeightedGraph<int> g(n);
  g.Read(m);
  int ans = 0;
  rep(i, n) {
    V<optional<int>> od = Dijkstra(g, i).dist;
    V<int> d;
    rep(j, n) if (j != i) d.pb(*od[j]);
    sort(d);
    int k = -1;
    rep(j, sz(d)) {
      while (k + 1 < sz(d) && d[k + 1] * r < d[j] * t) ++k;
      ans += k >= j ? k : k + 1;
    }
  }
  wt(ans);
}
