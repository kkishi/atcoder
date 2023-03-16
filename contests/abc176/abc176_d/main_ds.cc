#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "disjoint_set_2d.h"
#include "graph.h"

void Main() {
  ints(h, w, ch, cw, dh, dw);
  --ch, --cw, --dh, --dw;
  V<string> s(h);
  cin >> s;
  DisjointSet2D ds(h, w);
  rep(r, h) rep(c, w) each(nr, nc, adjacent(r, c)) if (inside(nr, nc, h, w)) {
    if (s[r][c] == '.' && s[nr][nc] == '.') ds.Union(r, c, nr, nc);
  }
  WeightedGraph<int> g(h * w);
  rep(r, h) rep(c, w) rep(dr, -2, 3) rep(dc, -2, 3) {
    int nr = r + dr;
    int nc = c + dc;
    if (inside(nr, nc, h, w)) {
      if (s[r][c] == '.' && s[nr][nc] == '.') {
        int x = ds.Find(r, c);
        int y = ds.Find(nr, nc);
        if (x != y) {
          g[x].eb(y, 1);
          g[y].eb(x, 1);
        }
      }
    }
  }
  auto ans = Dijkstra(g, ds.Find(ch, cw)).dist[ds.Find(dh, dw)];
  if (ans) {
    wt(*ans);
  } else {
    wt(-1);
  }
}
