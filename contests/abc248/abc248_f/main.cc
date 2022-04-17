#include <bits/stdc++.h>

#include <atcoder/modint>

#include "atcoder.h"
#include "disjoint_set.h"

using mint = atcoder::modint;

void Main() {
  vector next(1 << 4, vector(1 << 3, int(-1)));
  rep(i, 1 << 4) rep(j, 1 << 3) {
    DisjointSet ds(6);
    if (hasbit(i, 0)) ds.Union(0, 2);
    if (hasbit(i, 1)) ds.Union(1, 2);
    if (hasbit(i, 2)) ds.Union(0, 3);
    if (hasbit(i, 3)) ds.Union(1, 3);
    if (hasbit(j, 0)) ds.Union(2, 4);
    if (hasbit(j, 1)) ds.Union(4, 5);
    if (hasbit(j, 2)) ds.Union(3, 5);
    if ((!ds.Same(2, 4) && !ds.Same(2, 5)) ||
        (!ds.Same(3, 4) && !ds.Same(3, 5))) {
      continue;
    }
    int ni = 0;
    if (ds.Same(0, 4)) ni |= 1 << 0;
    if (ds.Same(1, 4)) ni |= 1 << 1;
    if (ds.Same(0, 5)) ni |= 1 << 2;
    if (ds.Same(1, 5)) ni |= 1 << 3;
    next[i][j] = ni;
  }

  ints(n, p);
  mint::set_mod(p);
  vector dp(n + 1, vector(n + 1, vector(1 << 4, mint(0))));
  dp[1][1][(2 << 2) | 1] = 1;
  dp[1][0][(1 << 4) - 1] = 1;
  rep(i, 1, n) rep(j, n) rep(k, 1, 1 << 4) {
    mint x = dp[i][j][k];
    if (x == 0) continue;
    rep(l, 1 << 3) {
      int nj = j + 3 - popcount(l);
      if (nj >= n) continue;
      int nk = next[k][l];
      if (nk == -1) continue;
      dp[i + 1][nj][nk] += x;
    }
  }
  V<int> ans;
  rep(i, 1, n) ans.eb(dp[n][i][(1 << 4) - 1].val());
  wt(ans);
}
