#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  int m = sz(s[0]);
  rep(i, n) rep(j, m) if (s[i][j] == '#') {
    rep(ni, i + 1, n) {
      int d = (ni - i);
      rep(nj, max(0, j - d), min(j + d + 1, m)) {
        if (s[ni][nj] == 'X') {
          s[i][j] = 'X';
        }
      }
    }
  }
  each(si, s) wt(si);
}
