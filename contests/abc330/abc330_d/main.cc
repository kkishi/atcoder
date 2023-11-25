#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  V<int> r(n), c(n);
  rep(i, n) rep(j, n) {
    r[i] += s[i][j] == 'o';
    c[i] += s[j][i] == 'o';
  }
  int ans = 0;
  rep(i, n) rep(j, n) if (s[i][j] == 'o') ans += (r[i] - 1) * (c[j] - 1);
  wt(ans);
}
