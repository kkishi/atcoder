#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(double, xs, ys, xt, yt);
  ints(n);
  const int N = n + 2;
  V<double> x(N), y(N), r(N);
  rep(i, n) cin >> x[i] >> y[i] >> r[i];
  const int s = n, t = n + 1;
  x[s] = xs, y[s] = ys;
  x[t] = xt, y[t] = yt;

  vector g(N, vector(N, double(0)));
  rep(i, N) rep(j, N) {
#define sq(x) (x) * (x)
    g[i][j] = max(0, sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j])) - (r[i] + r[j]));
  }

  const double inf = numeric_limits<double>::max() / 10;
  V<double> dist(N, inf);
  dist[s] = 0;
  low_priority_queue<pair<double, int>> que;
  que.push({0, s});
  while (!que.empty()) {
    auto [_, i] = que.top();
    que.pop();
    rep(j, N) if (chmin(dist[j], dist[i] + g[i][j])) que.push({dist[j], j});
  }
  wt(dist[t]);
}
