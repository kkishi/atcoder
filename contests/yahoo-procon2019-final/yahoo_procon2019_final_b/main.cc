#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "rerooting.h"

void Main() {
  auto f = [] {
    ints(n);
    BidirectedGraph<int> g(n);
    rep(n - 1) {
      ints(p, q);
      g.AddEdge(p - 1, q - 1);
    }
    return Rerooting<int, int>(
        g, [](int a, int b) -> int { return max(a, b); },
        [](auto&, int x) { return x + 1; });
  };
  V<int> a = f(), b = f();
  int d = max(max(a), max(b));
  sort(a);
  sort(b);
  V<int> s(sz(b) + 1);
  rep(i, sz(b)) s[i + 1] = s[i] + b[i];
  int ans = 0;
  each(x, a) {
    int i = lower_bound(all(b), d - (x + 1)) - b.begin();
    ans += d * i + (sz(b) - i) * (x + 1) + s[sz(b)] - s[i];
  }
  wt(ans);
}
