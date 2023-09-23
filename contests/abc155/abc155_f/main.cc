#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "graph.h"

void Main() {
  ints(n, m);
  V<pair<int, int>> bomb(n), cord(m);
  cin >> bomb >> cord;
  V<int> v;
  each(a, _, bomb) v.eb(a);
  Compressor c(v);
  each(a, _, bomb) a = c(a);
  each(l, r, cord) {
    l = c(l);
    r = c(r + 1);
  }

  V<int> state(n + 2);
  each(a, b, bomb) state[a + 1] = b;

  WeightedGraph<int> g(n + 1);
  rep(i, m) {
    auto [l, r] = cord[i];
    g[l].eb(r, i);
    g[r].eb(l, i);
  }

  V<int> ans;
  V<bool> seen(n + 1);
  rep(i, n + 1) if (!seen[i]) {
    int x = Fix([&](auto rec, int node) -> int {
      if (seen[node]) return 0;
      seen[node] = true;
      int cnt = state[node] ^ state[node + 1];
      each(child, i, g[node]) {
        int ccnt = rec(child);
        if (!even(ccnt)) ans.pb(i + 1);
        cnt += ccnt;
      }
      return cnt;
    })(i);
    if (!even(x)) {
      wt(-1);
      return;
    }
  }
  wt(sz(ans));
  sort(ans);
  wt(ans);
}
