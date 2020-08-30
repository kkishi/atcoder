#include <bits/stdc++.h>

#include "bellman_ford.h"
#include "graph.h"
#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, m, p);

  V<int> a(m), b(m), c(m);
  Graph<ll> bg(n);
  rep(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i], --b[i];
    bg.AddEdge(b[i], a[i], 0);
  }

  auto [bgd, _] = BellmanFord(bg, n - 1);

  Graph<ll> g(n);
  rep(i, m) if (bgd[a[i]] == 0) g.AddEdge(a[i], b[i], p - c[i]);

  if (auto [d, ok] = BellmanFord(g, 0); ok) {
    wt(max(-d[n - 1], 0LL));
  } else {
    wt(-1);
  }
}
