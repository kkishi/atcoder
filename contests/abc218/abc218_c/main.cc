#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n), t(n);
  cin >> s >> t;
  rep(4) {
    using T = tuple<int, int, int, int>;
    auto f = [&](const V<string>& v) -> T {
      int minr = big, maxr = -big;
      int minc = big, maxc = -big;
      rep(i, n) rep(j, n) if (v[i][j] == '#') {
        chmin(minr, i);
        chmax(maxr, i);
        chmin(minc, j);
        chmax(maxc, j);
      }
      return {minr, maxr, minc, maxc};
    };
    auto [sminr, smaxr, sminc, smaxc] = f(s);
    auto [tminr, tmaxr, tminc, tmaxc] = f(t);
    if (smaxr - sminr == tmaxr - tminr && smaxc - sminc == tmaxc - tminc) {
      bool ok = true;
      rep(i, sminr, smaxr + 1) rep(j, sminc, smaxc + 1) {
        if (s[i][j] != t[i - sminr + tminr][j - sminc + tminc]) {
          ok = false;
        }
      }
      if (ok) {
        wt(true);
        return;
      }
    }
    V<string> ns(n, string(n, ' '));
    rep(i, n) rep(j, n) { ns[j][n - 1 - i] = s[i][j]; }
    swap(ns, s);
  }
  wt(false);
}
