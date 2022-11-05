#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  wt([]() {
    ints(h, w);
    V<string> g(h);
    cin >> g;
    auto idx = [&](int r, int c) { return r * w + c; };
    int sr, sc;
    rep(r, h) rep(c, w) if (g[r][c] == 'S') sr = r, sc = c;
    DisjointSet ds(h * w);
    auto valid = [&](int r, int c) {
      return inside(r, c, h, w) && g[r][c] == '.';
    };
    rep(r, h) rep(c, w) {
      if (!valid(r, c)) continue;
      each(nr, nc, adjacent(r, c)) {
        if (!valid(nr, nc)) continue;
        ds.Union(idx(r, c), idx(nr, nc));
      }
    }
    V<pair<int, int>> adj;
    each(nr, nc, adjacent(sr, sc)) if (valid(nr, nc)) adj.eb(nr, nc);
    rep(i, sz(adj)) rep(j, i) {
      auto [r, c] = adj[i];
      auto [R, C] = adj[j];
      if (ds.Same(idx(r, c), idx(R, C))) return true;
    }
    return false;
  }());
}
