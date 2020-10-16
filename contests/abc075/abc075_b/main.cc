#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  rep(i, h) rep(j, w) if (s[i][j] == '.') {
    int b = 0;
    rep(k, -1, 2) rep(l, -1, 2) {
      int n = i + k, m = j + l;
      if (0 <= n && n < h && 0 <= m && m < w && s[n][m] == '#') ++b;
    }
    s[i][j] = '0' + b;
  }
  rep(i, h) wt(s[i]);
}
