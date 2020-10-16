#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, M, Q);

  VV<int> trains(N + 1, V<int>(N + 1));
  rep(i, M) {
    ints(L, R);
    trains[L][R]++;
  }

  VV<int> sum(N + 2, V<int>(N + 2));
  for (int l = N; l >= 1; --l) {
    for (int r = 1; r <= N; ++r) {
      sum[l][r] =
          sum[l + 1][r] + sum[l][r - 1] - sum[l + 1][r - 1] + trains[l][r];
    }
  }

  rep(i, Q) {
    ints(p, q);
    wt(sum[p][q]);
  }
}
