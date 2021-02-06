#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h), t(h);
  cin >> s >> t;
  int lr = big, hr = -big, lc = big, hc = -big;
  rep(i, h) rep(j, w) if (t[i][j] == '#') {
    chmin(lr, i);
    chmax(hr, i);
    chmin(lc, j);
    chmax(hc, j);
  }
  vector nt(hr - lr + 1, string(hc - lc + 1, '.'));
  rep(i, hr - lr + 1) rep(j, hc - lc + 1) nt[i][j] = t[i + lr][j + lc];
  swap(t, nt);
  bool ok = false;
  rep(4) {
    vector nt(sz(t[0]), string(sz(t), '.'));
    rep(i, sz(t)) rep(j, sz(t[i])) nt[j][sz(t) - 1 - i] = t[i][j];
    swap(t, nt);
    rep(i, sz(s) - sz(t) + 1) rep(j, sz(s[0]) - sz(t[0]) + 1) {
      bool ng = false;
      rep(k, sz(t)) rep(l, sz(t[0])) {
        if (s[i + k][j + l] == '#' && t[k][l] == '#') ng = true;
      }
      if (!ng) ok = true;
    }
  }
  wt(ok);
}
