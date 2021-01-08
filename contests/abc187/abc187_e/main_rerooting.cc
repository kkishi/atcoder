#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "rerooting.h"

void Main() {
  ints(n);
  V<int> a(n - 1), b(n - 1);
  rep(i, n - 1) cin >> a[i] >> b[i];
  V<int> xa(n - 1), xb(n - 1);
  ints(q);
  rep(q) {
    ints(t, e, x);
    (t == 1 ? xa : xb)[e - 1] += x;
  }
  BidirectedGraph<int> g(n);
  rep(i, n - 1) {
    auto [f, r] = g.AddEdge(a[i] - 1, b[i] - 1);
    f.weight = xa[i];
    r.weight = xb[i];
  }
  V<int> res = Rerooting<int, int>(
      g, [](int a, int b) { return a + b; },
      [](const auto& e, int x) { return e.weight + x; });
  each(r, res) wt(r);
}
