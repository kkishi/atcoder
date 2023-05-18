#include <bits/stdc++.h>

#include "atcoder.h"
#include "grid.h"
#include "travelling_salesperson_problem.h"

void Main() {
  ints(h, w, t);
  V<string> a(h);
  cin >> a;
  Grid<int> g(h, w);
  int sr, sc, gr, gc;
  V<pair<int, int>> candy;
  rep(i, h) rep(j, w) {
    char c = a[i][j];
    if (c != '#') g.Set(i, j, 1);
    if (c == 'S') sr = i, sc = j;
    if (c == 'G') gr = i, gc = j;
    if (c == 'o') candy.eb(i, j);
  }
  candy.eb(sr, sc);
  candy.eb(gr, gc);
  int N = sz(candy);
  vector dist(N, vector(N, big));
  rep(i, N) {
    auto [r, c] = candy[i];
    auto gd = g.Distance(r, c);
    rep(j, N) {
      auto [nr, nc] = candy[j];
      optional<int> d = gd[nr][nc];
      if (d) dist[i][j] = *d;
    }
  }
  vector dp(1 << N, vector(N, big));
  dp[1 << (N - 2)][N - 2] = 0;
  TravellingSalespersonProblem(dp, dist);
  int ans = -1;
  rep(mask, 1 << N) if (dp[mask][N - 1] <= t) chmax(ans, popcount(mask) - 2);
  wt(ans);
}
