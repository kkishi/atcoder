#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector v(n, vector(n, big));
  rep(i, m) {
    ints(a, b, c);
    chmin(v[a - 1][b - 1], c);
  }
  int ans = 0;
  rep(k, n) rep(i, n) rep(j, n) {
    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
    if (i != j && v[i][j] < big) ans += v[i][j];
  }
  wt(ans);
}
