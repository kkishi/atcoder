#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  V<char> d(n);
  rep(i, n) cin >> x[i] >> y[i] >> d[i];
  V<double> t = {0};
  rep(2) {
    rep(2) {
      // Find the inflection points of y_max.
      int U = -big, D = -big, H = -big;
      rep(i, n) chmax((d[i] == 'U' ? U : d[i] == 'D' ? D : H), y[i]);
      if (H != -big) {
        if (U != -big && U < H) t.eb(H - U);  // _/
        if (D != -big && D > H) t.eb(D - H);  // \_
      }
      if (U != -big && D != -big && U < D) t.eb((D - U) * 0.5);  // \/

      // Flip upside down.
      each(e, y) e = -e;
      each(e, d) if (e == 'D' || e == 'U') e = 'D' + 'U' - e;
    }
    // Flip x and y.
    swap(x, y);
    each(e, d) {
      if (e == 'D' || e == 'L') e = 'D' + 'L' - e;
      if (e == 'U' || e == 'R') e = 'U' + 'R' - e;
    }
  }
  double ans = big;
  each(e, t) {
    V<double> xs, ys;
    rep(i, n) xs.eb(x[i] + e * (d[i] == 'R' ? 1 : d[i] == 'L' ? -1 : 0));
    rep(i, n) ys.eb(y[i] + e * (d[i] == 'U' ? 1 : d[i] == 'D' ? -1 : 0));
    chmin(ans, (max(xs) - min(xs)) * (max(ys) - min(ys)));
  }
  wt(ans);
}
