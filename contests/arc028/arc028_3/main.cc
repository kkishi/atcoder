#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N);
  VV<int> to(N);
  rep(i, 1, N) {
    ints(p);
    to[i].push_back(p);
    to[p].push_back(i);
  }
  V<int> ans(N);
  Fix([&](auto rec, int n, int p) -> int {
    int sum = 0;
    int maxi = 0;
    for (int c : to[n]) {
      if (c == p) continue;
      int res = rec(c, n);
      sum += res;
      chmax(maxi, res);
    }
    ans[n] = max(maxi, N - (sum + 1));
    return sum + 1;
  })(0, -1);
  rep(i, N) wt(ans[i]);
}
