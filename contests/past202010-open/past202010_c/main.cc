#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector s(n + 2, string(m + 2, '.'));
  rep(i, n) {
    strings(t);
    rep(j, m) s[i + 1][j + 1] = t[j];
  }
  rep(r, n) {
    rep(c, m) {
      int cnt = 0;
      rep(i, -1, 2) rep(j, -1, 2) cnt += s[r + 1 + i][c + 1 + j] == '#';
      cout << cnt;
    }
    cout << endl;
  }
}
