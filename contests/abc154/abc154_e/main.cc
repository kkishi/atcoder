#include <bits/stdc++.h>

#include "atcoder.h"

int dp_eq[101][5];
int dp_lo[101][5];

void Main() {
  strings(N);
  ints(K);
  dp_eq[0][0] = 1;
  rep(i, N.size()) {
    for (int z = 0; z <= 3; ++z) {
      int d = N[i] - '0';
      // Equal to d
      dp_eq[i + 1][z + (d != 0)] += dp_eq[i][z];
      dp_lo[i + 1][z + (d != 0)] += dp_lo[i][z];
      // Lower than d (zero)
      if (d > 0) dp_lo[i + 1][z] += dp_eq[i][z] + dp_lo[i][z];
      // Lower than d (non-zero)
      if (d > 1) dp_lo[i + 1][z + 1] += (dp_eq[i][z] + dp_lo[i][z]) * (d - 1);
      // Highe than d
      dp_lo[i + 1][z + 1] += dp_lo[i][z] * (9 - d);
    }
  }
  wt(dp_eq[N.size()][K] + dp_lo[N.size()][K]);
}
