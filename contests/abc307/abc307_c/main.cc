#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  auto canon = [&](int& h, int& w, V<string>& g) {
    int mih = big, mah = -big, miw = big, maw = -big;
    rep(i, h) rep(j, w) if (g[i][j] == '#') {
      chmin(mih, i);
      chmax(mah, i);
      chmin(miw, j);
      chmax(maw, j);
    }
    int nh = mah - mih + 1;
    int nw = maw - miw + 1;
    V<string> G(nh, string(nw, '.'));
    rep(i, nh) rep(j, nw) G[i][j] = g[mih + i][miw + j];
    h = nh;
    w = nw;
    swap(g, G);
  };

  ints(ha, wa);
  V<string> a(ha);
  cin >> a;
  canon(ha, wa, a);

  ints(hb, wb);
  V<string> b(hb);
  cin >> b;
  canon(hb, wb, b);

  ints(hx, wx);
  V<string> x(hx);
  cin >> x;

  if (max(ha, hb) > hx) return false;
  if (max(wa, wb) > wx) return false;

  rep(i, hx - ha + 1) {
    rep(j, wx - wa + 1) {
      rep(k, hx - hb + 1) {
        rep(l, wx - wb + 1) {
          V<string> X(hx, string(wx, '.'));
          rep(r, ha) rep(c, wa) if (a[r][c] == '#') X[r + i][c + j] = '#';
          rep(r, hb) rep(c, wb) if (b[r][c] == '#') X[r + k][c + l] = '#';
          if (X == x) return true;
        }
      }
    }
  }
  return false;
}
