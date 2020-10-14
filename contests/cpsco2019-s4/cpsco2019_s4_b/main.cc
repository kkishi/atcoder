#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d);
  V<string> s(d);
  cin >> s;
  int ans = 0;
  rep(i, d - 1) rep(j, i, d) {
    int x = 0;
    rep(k, n) x += s[i][k] == 'o' || s[j][k] == 'o';
    chmax(ans, x);
  }
  wt(ans);
}
