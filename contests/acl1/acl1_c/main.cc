#include <bits/stdc++.h>

#include <atcoder/mincostflow>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> s(n);
  cin >> s;

  V<pair<int, int>> p;
  V<VV<int>> dps;
  rep(r, n) rep(c, m) {
    if (s[r][c] != 'o') continue;
    p.push_back({r, c});
    VV<int> dp(n, V<int>(m, -1));
    dp[r][c] = 0;
    rep(nr, r, n) rep(nc, c, m) {
      if (s[nr][nc] == '#') continue;
      if (nr > 0 && dp[nr - 1][nc] != -1) chmax(dp[nr][nc], dp[nr - 1][nc] + 1);
      if (nc > 0 && dp[nr][nc - 1] != -1) chmax(dp[nr][nc], dp[nr][nc - 1] + 1);
    }
    dps.push_back(dp);
  }

  int src = sz(p) + n * m, dst = src + 1;
  atcoder::mcf_graph<int, int> g(dst + 1);
  const int big = n * m * 2;
  rep(i, sz(p)) {
    g.add_edge(src, i, 1, 0);
    rep(r, n) rep(c, m) if (int cap = dps[i][r][c]; cap != -1) {
      int index = sz(p) + m * r + c;
      g.add_edge(i, index, 1, big - cap);
    }
  }
  rep(r, n) rep(c, m) {
    int index = sz(p) + m * r + c;
    g.add_edge(index, dst, 1, 0);
  }

  auto [cap, cost] = g.flow(src, dst);
  wt(cap * big - cost);

  // Debug
  V<string> res(s);
  rep(r, n) rep(c, m) if (res[r][c] == 'o') res[r][c] = '.';
  for (const auto& e : g.edges()) {
    if (e.to == dst && e.flow == 1) {
      int rc = e.from - sz(p);
      res[rc / m][rc % m] = 'o';
    }
  }
  rep(i, n) dbg(res[i]);
}
