#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  mint ans = 1;
  map<int, int> r, b, t;
  rep(i, h) rep(j, w) {
    ++t[i + j];
    if (s[i][j] == 'R') ++r[i + j];
    if (s[i][j] == 'B') ++b[i + j];
  }
  each(k, v, t) {
    if (r[k] > 0 && b[k] > 0) {
      wt(0);
      return;
    }
    if (r[k] == 0 && b[k] == 0) {
      ans *= 2;
    }
  }
  wt(ans);
}
