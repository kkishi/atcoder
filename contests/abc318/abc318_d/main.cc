#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector d(n, vector(n, int(0)));
  rep(i, n) rep(j, i + 1, n) cin >> d[i][j];

  V<bool> used(n);
  int sum = 0;
  int ans = -big;
  Fix([&](auto rec, int depth) {
    chmax(ans, sum);
    if (depth == n) {
      return;
    }
    rec(depth + 1);
    if (!used[depth]) {
      rep(j, depth + 1, n) if (!used[j]) {
        used[j] = true;
        sum += d[depth][j];
        rec(depth + 1);
        sum -= d[depth][j];
        used[j] = false;
      }
    }
  })(0);
  wt(ans);
}
