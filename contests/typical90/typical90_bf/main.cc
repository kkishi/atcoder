#include <bits/stdc++.h>

#include "atcoder.h"

int digitsum(int x) { return x == 0 ? 0 : x % 10 + digitsum(x / 10); }

void Main() {
  const int N = 100000;
  vector next(60, vector(N, int(0)));
  rep(i, N) next[0][i] = (i + digitsum(i)) % N;
  rep(i, 1, 60) rep(j, N) next[i][j] = next[i - 1][next[i - 1][j]];
  ints(n, k);
  rep(i, 60) if (hasbit(k, i)) n = next[i][n];
  wt(n);
}
