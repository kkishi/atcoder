#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"

void Main() {
  ints(n, t);
  V<int> ax(n), ay(n), bx(n), by(n);
  rep(i, n) cin >> ax[i] >> ay[i];
  rep(i, n) cin >> bx[i] >> by[i];

  map<pair<int, int>, int> bm;
  rep(i, n) bm[{bx[i], by[i]}] = i;

  atcoder::mf_graph<int> g(n * 2 + 2);
  int S = n * 2;
  int T = S + 1;
  int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
  int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
  rep(i, n) {
    g.add_edge(S, i, 1);
    rep(j, 8) {
      auto it = bm.find({ax[i] + dx[j] * t, ay[i] + dy[j] * t});
      if (it != bm.end()) {
        g.add_edge(i, n + it->second, 1);
      }
    }
    g.add_edge(n + i, T, 1);
  }
  int f = g.flow(S, T);
  if (f < n) {
    wt("No");
    return;
  }
  wt("Yes");
  V<int> ans(n);
  for (auto [from, to, cap, flow] : g.edges()) {
    if (0 <= from && from < n && n <= to && to < n * 2 && flow == 1) {
#define sign(x) ((x) < 0 ? -1 : (x) > 0 ? 1 : 0)
      int sx = sign(bx[to - n] - ax[from]);
      int sy = sign(by[to - n] - ay[from]);
      rep(i, 8) if (sx == dx[i] && sy == dy[i]) { ans[from] = i + 1; }
    }
  }
  wt(ans);
}
