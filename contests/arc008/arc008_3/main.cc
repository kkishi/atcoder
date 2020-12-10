#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<double> x(n), y(n), t(n), r(n);
  rep(i, n) cin >> x[i] >> y[i] >> t[i] >> r[i];

  double inf = numeric_limits<double>::max();
  V<double> dist(n, inf);
  dist[0] = 0;
  V<bool> done(n);

  double ans = 0;
  rep(iter, n) {
    double md = numeric_limits<double>::max();
    int mi = -1;
    rep(i, n) if (!done[i] && chmin(md, dist[i])) mi = i;
    done[mi] = true;
    if (iter > 0) chmax(ans, dist[mi] + (n - 1 - iter));
    rep(i, n) if (!done[i]) {
      auto sq = [](double x) { return x * x; };
      double d = sqrt(sq(x[i] - x[mi]) + sq(y[i] - y[mi]));
      chmin(dist[i], dist[mi] + d / min(t[mi], r[i]));
    }
  }
  cout << setprecision(6);
  wt(ans);
}
