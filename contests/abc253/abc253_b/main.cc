#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  V<array<int, 2>> v;
  rep(i, h) rep(j, w) if (s[i][j] == 'o') v.pb({i, j});
  int ans = 0;
  rep(i, 2) ans += abs(v[0][i] - v[1][i]);
  wt(ans);
}
