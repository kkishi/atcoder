#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  CumulativeSum2D s(a);

  int tot = s.Get(h - 1, w - 1);
  VV<int> HS;
  rep(i0, h) {
    int x = s.Get(i0, w - 1);
    if (tot % x != 0) continue;
    V<int> v;
    rep(i, h + 1) if (s.Get(i - 1, w - 1) % x == 0) v.eb(i);
    if (sz(v) == tot / x + 1) HS.pb(v);
  }
  VV<int> WS;
  rep(i0, w) {
    int x = s.Get(h - 1, i0);
    if (tot % x != 0) continue;
    V<int> v;
    rep(i, w + 1) if (s.Get(h - 1, i - 1) % x == 0) v.eb(i);
    if (sz(v) == tot / x + 1) WS.pb(v);
  }
  int ans = 0;
  each(H, HS) each(W, WS) {
    set<int> sum;
    rep(i, sz(H) - 1) rep(j, sz(W) - 1) {
      int lr = H[i];
      int hr = H[i + 1];
      int lc = W[j];
      int hc = W[j + 1];
      sum.insert(s.Get(lr, lc, hr - 1, hc - 1));
    }
    if (sz(sum) == 1) ++ans;
  }
  wt(ans - 1);
}
