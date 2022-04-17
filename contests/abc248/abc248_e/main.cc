#include <bits/stdc++.h>

#include "atcoder.h"

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
    int g = gcd(dx, dy);
    dx /= g;
    dy /= g;
    if (dx < 0) {
      dx = -dx;
      dy = -dy;
    }
    {
      int p = y[i] * dx - x[i] * dy;
      int q = dx;
      int g = gcd(p, q);
      p /= g;
      q /= g;
      if (p < 0) {
        p = -p;
        q = -q;
      }
      auto [_, ok] = seen.emplace(P{dx, dy}, P{p, q});
      if (!ok) continue;
    }
    st.eb(i, P{dx, dy});
  }
  vector cache(n, vector(n, P{}));
  rep(i, n) rep(j, n) {
    int dx = x[j] - x[i];
    int dy = y[j] - y[i];
    if (dx == 0 || dy == 0) continue;
    int g = gcd(dx, dy);
    dx /= g;
    dy /= g;
    if (dx < 0) {
      dx = -dx;
      dy = -dy;
    }
    cache[i][j] = P{dx, dy};
  }
  V<set<P>> counted(n);
  each(I, q, st) {
    int cnt = 0;
    rep(i, n) {
      if (i == I) {
        ++cnt;
        continue;
      }
      auto [dx, dy] = cache[i][I];
      if (q == P{dx, dy}) {
        ++cnt;
      }
    }
    if (cnt >= K) ++ans;
    continue;
  }
  wt(ans);
}
