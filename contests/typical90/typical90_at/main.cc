#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> v(3, V<int>(n));
  cin >> v;
  int N = 46;
  VV<int> vm(3, V<int>(N));
  rep(i, 3) rep(j, n)++ vm[i][v[i][j] % N];
  int ans = 0;
  rep(i, N) rep(j, N) ans += vm[0][i] * vm[1][j] * vm[2][(N * 3 - (i + j)) % N];
  wt(ans);
}
