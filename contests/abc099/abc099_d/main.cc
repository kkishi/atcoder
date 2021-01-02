#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, C);
  vector D(C, vector(C, 0));
  rep(i, C) rep(j, C) cin >> D[i][j];
  vector c(N, vector(N, 0));
  rep(i, N) rep(j, N) cin >> c[i][j];

  VV<pair<int, int>> cost(3);
  rep(i, 3) {
    V<int> cs;
    rep(j, N) rep(k, N) if (((j + 1) + (k + 1)) % 3 == i) {
      cs.push_back(c[j][k]);
    }
    rep(j, C) {
      int sum = 0;
      for (int csi : cs) sum += D[csi - 1][j];
      cost[i].push_back({sum, j});
    }
    sort(all(cost[i]));
  }
  int ans = big;
  V<int> idx = {0, 1, 2};
  do {
    set<int> used;
    int sum = 0;
    rep(i, 3) {
      for (auto& p : cost[idx[i]]) {
        if (used.insert(p.second).second) {
          sum += p.first;
          break;
        }
      }
    }
    chmin(ans, sum);
  } while (next_permutation(all(idx)));
  wt(ans);
}
