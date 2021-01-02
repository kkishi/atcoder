#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"

void Main() {
  ints(h, w, m);
  V<int> x(m), y(m);
  rep(i, m) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
  }
  swap(h, w);  // Why???

  auto solve = [&]() -> pair<int, int> {
    int hx = w - 1;
    rep(i, m) if (y[i] == 0) chmin(hx, x[i] - 1);

    V<int> hy(w, h - 1);
    rep(i, m) chmin(hy[x[i]], y[i] - 1);

    VV<int> xy(w);
    rep(i, m) xy[x[i]].pb(y[i]);

    BIT<int> ys(h);
    rep(i, hy[0] + 1) ys.Add(i, 1);

    int cnt = 0, excess = 0;
    rep(i, hx + 1) {
      cnt += hy[i] + 1;
      excess += ys.Sum(hy[i]);
      for (int y : xy[i]) ys.Set(y, 0);
    }
    return {cnt, excess};
  };
  auto [a, b] = solve();
  swap(h, w);
  rep(i, m) swap(x[i], y[i]);
  auto [c, d] = solve();
  assert(b == d);
  wt(a + c - b);
}
