#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m, r, t);
  Graph<int> g(n);
  rep(m) {
    ints(a, b, c);
    --a, --b;
    g.AddEdge(a, b, c);
    g.AddEdge(b, a, c);
  }
  int ans = 0;
  rep(i, n) {
    V<optional<int>> od = Dijkstra(g, i).dist;
    V<int> d;
    rep(j, n) if (j != i) d.pb(*od[j]);
    sort(all(d));
    int k = -1;
    rep(j, sz(d)) {
      while (k + 1 < sz(d) && d[k + 1] * r < d[j] * t) ++k;
      ans += k >= j ? k : k + 1;
    }
  }
  wt(ans);
}
