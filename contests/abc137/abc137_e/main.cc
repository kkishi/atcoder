#include <bits/stdc++.h>

#include "atcoder.h"
#include "bellman_ford.h"
#include "graph.h"

void Main() {
  ints(n, m, p);

  V<int> a(m), b(m), c(m);
  WeightedGraph<int> bg(n);
  rep(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i], --b[i];
    bg[b[i]].eb(a[i], 0);
  }

  auto [bgd, _] = BellmanFord(bg, n - 1);

  WeightedGraph<int> g(n);
  rep(i, m) if (bgd[a[i]] == 0) g[a[i]].eb(b[i], p - c[i]);

  if (auto [d, ok] = BellmanFord(g, 0); ok) {
    wt(max(-*d[n - 1], 0LL));
  } else {
    wt(-1);
  }
}
