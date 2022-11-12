#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra_map.h"
#include "graph.h"

void Main() {
  ints(n, m, k);
  WeightedGraph<int> g(n);
  g.Read(m);
  V<bool> has_switch(n);
  rep(k) {
    ints(s);
    has_switch[s - 1] = true;
  }
  using P = pair<int, int>;
  auto dist = Dijkstra<P, int>(P{0, 0}, [&](P s, auto push) {
    auto [node, state] = s;
    if (has_switch[node]) push({node, 1 - state}, 0);
    each(child, weight, g[node]) {
      if (state != weight) push({child, state}, 1);
    }
  });
  int ans = big;
  rep(i, 2) if (dist.count({n - 1, i})) chmin(ans, dist[{n - 1, i}]);
  if (ans == big) ans = -1;
  wt(ans);
}
