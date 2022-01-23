#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector a(n * 2, vector(n * 2, int(0)));
  rep(i, n * 2 - 1) rep(j, i + 1, n * 2) cin >> a[i][j];
  int ans = 0;
  V<bool> used(n * 2);
  Fix([&](auto rec, int depth, int b) -> void {
    if (depth == n) {
      chmax(ans, b);
      return;
    }
    rep(i, n * 2) if (!used[i]) {
      used[i] = true;
      rep(j, i + 1, n * 2) if (!used[j]) {
        used[j] = true;
        rec(depth + 1, b ^ a[i][j]);
        used[j] = false;
      }
      used[i] = false;
      return;
    }
  })(0, 0);
  wt(ans);
}
