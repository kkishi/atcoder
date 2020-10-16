#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> x(n), y(n), p(n);
  rep(i, n) cin >> x[i] >> y[i] >> p[i];
  vector<int> ans(n + 1, numeric_limits<int>::max());
  vector<int> dist(n);
  rep(i, n) dist[i] = min(abs(x[i]), abs(y[i]));
  Fix([&](auto rec, int depth, int k, vector<int> dist) {
    if (depth == n) {
      int S = 0;
      rep(i, n) S += p[i] * dist[i];
      chmin(ans[k], S);
      return;
    }
    rec(depth + 1, k, dist);
    {
      // x
      vector<int> ndist = dist;
      rep(i, n) chmin(ndist[i], abs(x[i] - x[depth]));
      rec(depth + 1, k + 1, ndist);
    }
    {
      // y
      vector<int> ndist = dist;
      rep(i, n) chmin(ndist[i], abs(y[i] - y[depth]));
      rec(depth + 1, k + 1, ndist);
    }
  })(0, 0, dist);
  for (int k = 0; k <= n; ++k) {
    wt(ans[k]);
  }
}
