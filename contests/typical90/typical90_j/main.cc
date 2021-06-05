#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> c(n), p(n);
  rep(i, n) cin >> c[i] >> p[i];
  vector sum(2, vector(n + 1, int(0)));
  rep(i, n) {
    rep(j, 2) {
      sum[j][i + 1] = sum[j][i];
      if (c[i] == j + 1) sum[j][i + 1] += p[i];
    }
  }
  ints(q);
  rep(q) {
    ints(l, r);
    wt(sum[0][r] - sum[0][l - 1], sum[1][r] - sum[1][l - 1]);
  }
}
