#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, t, l);
  const int L = 31;
  vector e(L, vector(n, vector(n, big)));
  rep(i, t) {
    ints(u, v);
    chmin(e[0][u - 1][v - 1], i + 1);
  }
  rep(i, 1, L) rep(u, n) rep(v, n) rep(m, n) {
    chmin(e[i][u][v], max(e[i - 1][u][m], e[i - 1][m][v]));
  }
  vector ans(n, big);
  ans[0] = 0;
  rep(i, L) if ((l >> i) & 1) {
    vector nans(n, big);
    rep(j, n) rep(k, n) chmin(nans[k], max(ans[j], e[i][j][k]));
    swap(ans, nans);
  }
  each(e, ans) if (e == big) e = -1;
  wt(ans);
}
