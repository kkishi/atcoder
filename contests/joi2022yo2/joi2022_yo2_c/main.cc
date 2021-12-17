#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  vector s(h + 1, vector(w + 1, int(0)));
  rep(i, h) rep(j, w) {
    s[i + 1][j + 1] = a[i][j] + s[i][j + 1] + s[i + 1][j] - s[i][j];
  }
  int tot = s[h][w];
  VV<int> HS;
  rep(i0, 1, h + 1) {
    int x = s[i0][w];
    if (tot % x != 0) continue;
    V<int> v;
    rep(i, h + 1) if (s[i][w] % x == 0) v.eb(i);
    if (sz(v) == tot / x + 1) HS.pb(v);
  }
  VV<int> WS;
  rep(i0, 1, w + 1) {
    int x = s[h][i0];
    if (tot % x != 0) continue;
    V<int> v;
    rep(i, w + 1) if (s[h][i] % x == 0) v.eb(i);
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
      int x = s[hr][hc] - s[lr][hc] - s[hr][lc] + s[lr][lc];
      sum.insert(x);
    }
    if (sz(sum) == 1) ++ans;
  }
  wt(ans - 1);
}
