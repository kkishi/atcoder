#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(R, C, K, N);
  V<int> r(N), c(N);
  rep(i, N) {
    cin >> r[i] >> c[i];
    --r[i], --c[i];
  }
  V<int> rs(R), cs(C);
  VV<int> rc(R);
  rep(i, N) {
    ++rs[r[i]];
    ++cs[c[i]];
    rc[r[i]].pb(c[i]);
  }
  V<int> rcs(N + 1);
  rep(i, C)++ rcs[cs[i]];
  int ans = 0;
  rep(i, R) {
    int rem = K - rs[i];
    if (rem < 0) continue;
    ans += rcs[rem];
    for (int c : rc[i]) {
      if (cs[c] == rem) {
        --ans;
      } else if (cs[c] == rem + 1) {
        ++ans;
      }
    }
  }
  wt(ans);
}
