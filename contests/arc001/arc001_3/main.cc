#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<string> c(8);
  cin >> c;
  auto check = [&](int i, int j) {
    rep(k, 8) rep(l, 8) {
      if (k != i || l != j) {
        if (i == k || j == l || (i + j == k + l) || (i - j == k - l)) {
          if (c[k][l] == 'Q') return false;
        }
      }
    }
    return true;
  };
  rep(i, 8) rep(j, 8) if (c[i][j] == 'Q' && !check(i, j)) {
    wt("No Answer");
    return;
  }
  Fix([&](auto rec, int depth) -> void {
    if (depth == 5) {
      each(e, c) wt(e);
      exit(0);
    }
    rep(i, 8) rep(j, 8) if (c[i][j] == '.') {
      c[i][j] = 'Q';
      if (check(i, j)) rec(depth + 1);
      c[i][j] = '.';
    }
  })(0);
  wt("No Answer");
}
