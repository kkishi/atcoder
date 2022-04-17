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
  V<pair<int, P>> st;
  set<pair<P, P>> seen;
  rep(i, n) rep(j, i + 1, n) {
    int dx = x[j] - x[i];
    int dy = y[j] - y[i];
    if (dx == 0 || dy == 0) continue;
    Rational r = {dx, dy};
    r.Normalize();
    {
      if (!seen.emplace(r, Rational::Normalized(y[i] * dx - x[i] * dy, dx))
               .second)
        continue;
    }
    st.eb(i, r);
  }
  vector cache(n, vector(n, P{}));
  rep(i, n) rep(j, n) {
    int dx = x[j] - x[i];
    int dy = y[j] - y[i];
    if (dx == 0 || dy == 0) continue;
    cache[i][j] = Rational::Normalized(dx, dy);
  }
  each(I, q, st) {
    int cnt = 0;
    rep(i, n) {
      if (i == I || q == cache[i][I]) {
        ++cnt;
      }
    }
    if (cnt >= K) ++ans;
  }
  wt(ans);
}
