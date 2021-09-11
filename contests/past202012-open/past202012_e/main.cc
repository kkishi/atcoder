#include <bits/stdc++.h>

#include "atcoder.h"
#include "rotate90.h"

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
    t = Rotate90(t);
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
