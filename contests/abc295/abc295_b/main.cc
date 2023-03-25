#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, c);
  V<string> s(r);
  cin >> s;
  V<string> ans = s;
  rep(i, r) rep(j, c) rep(k, r) rep(l, c) {
    int x = s[k][l] - '0';
    if (1 <= x && x <= 9 && (abs(i - k) + abs(j - l) <= x)) {
      ans[i][j] = '.';
    }
  }
  each(e, ans) wt(e);
}
