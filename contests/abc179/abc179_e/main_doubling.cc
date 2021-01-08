#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, m);
  VV<pair<int, int>> to(m, V<pair<int, int>>(40));
  rep(i, m) to[i][0] = {i * i % m, i};
  for (int p = 1; p < 40; ++p) {
    rep(i, m) {
      auto [j, u] = to[i][p - 1];
      auto [k, v] = to[j][p - 1];
      to[i][p] = {k, u + v};
    }
  }
  int ans = 0;
  rrep(p, 40) if (hasbit(n, p)) {
    ans += to[x][p].second;
    x = to[x][p].first;
    n -= 1LL << p;
  }
  wt(ans);
}
