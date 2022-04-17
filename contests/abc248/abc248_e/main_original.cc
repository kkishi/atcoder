#include <bits/stdc++.h>

#include "atcoder.h"
#include "rational.h"

void Main() {
  ints(n, K);
  if (K == 1) {
    wt("Infinity");
    return;
  }
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  int ans = 0;

  map<int, int> xs, ys;
  each(e, x)++ xs[e];
  each(e, y)++ ys[e];
  each(k, v, xs) if (v >= K)++ ans;
  each(k, v, ys) if (v >= K)++ ans;

  using P = pair<int, int>;
  vector slope(n, vector(n, P()));
  rep(i, n) rep(j, n) {
    int dx = x[j] - x[i];
    int dy = y[j] - y[i];
    if (dx == 0 || dy == 0) continue;
    Rational r = {dx, dy};
    r.Normalize();
    slope[i][j] = r;
  }
  rep(i, n) rep(j, n) if (j != i) {
    P s = slope[i][j];
    if (s == P{0, 0}) continue;
    V<P> ps;
    P I = {x[i], y[i]};
    P J = {x[j], y[j]};
    ps.eb(I);
    ps.eb(J);
    rep(k, n) if (k != i && k != j) {
      P t = slope[i][k];
      if (s == t) ps.eb(x[k], y[k]);
    }
    sort(ps);
    if (ps[0] == I && ps[1] == J) {
      if (sz(ps) >= K) ++ans;
    }
  }
  wt(ans);
}
