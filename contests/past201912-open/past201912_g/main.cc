#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> a(n, V<int>(n));
  rep(i, n - 1) {
    rep(j, i + 1, n) {
      ints(ai);
      a[i][j] = a[j][i] = ai;
    }
  }
  int ans = -big;
  Fix([&](auto rec, int depth, V<int> groups, int score) {
    if (depth == n) {
      chmax(ans, score);
      return;
    }
    rep(i, 3) {
      int x = 0;
      rep(j, depth) if (groups[j] == i) x += a[j][depth];
      groups[depth] = i;
      rec(depth + 1, groups, x + score);
    }
  })(0, V<int>(n), 0);
  wt(ans);
}
