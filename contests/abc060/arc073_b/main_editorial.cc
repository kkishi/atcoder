#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, W);
  V<int> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];

  int w0 = w[0];
  VV<int> V(4);
  rep(i, n) V[w[i] - w0].pb(v[i]);
  rep(i, 4) sort(V[i], greater{});

  int ans = 0;
  rep(i, sz(V[0]) + 1) rep(j, sz(V[1]) + 1) rep(k, sz(V[2]) + 1)
      rep(l, sz(V[3]) + 1) {
    if (i * w0 + j * (w0 + 1) + k * (w0 + 2) + l * (w0 + 3) <= W) {
      int sum = 0;
      rep(m, i) sum += V[0][m];
      rep(m, j) sum += V[1][m];
      rep(m, k) sum += V[2][m];
      rep(m, l) sum += V[3][m];
      chmax(ans, sum);
    }
  }
  wt(ans);
}
