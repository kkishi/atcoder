#include <bits/stdc++.h>

#include "atcoder.h"
#include "rotate90.h"

void Main() {
  ints(n);
  V<string> s(n), t(n);
  cin >> s >> t;
  wt([&] {
    rep(4) {
      s = Rotate90(s);
      auto f = [&](const V<string>& v) {
        int minr = big, minc = big;
        rep(i, n) rep(j, n) if (v[i][j] == '#') {
          chmin(minr, i);
          chmin(minc, j);
        }
        V<string> w(n, string(n, '.'));
        rep(i, minr, n) rep(j, minc, n) w[i - minr][j - minc] = v[i][j];
        return w;
      };
      if (f(s) == f(t)) return true;
    }
    return false;
  }());
}
