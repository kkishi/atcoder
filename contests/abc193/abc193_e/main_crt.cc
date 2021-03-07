#include <bits/stdc++.h>

#include <atcoder/math>

#include "atcoder.h"

int Solve() {
  ints(x, y, p, q);
  int a = 2 * (x + y);
  int b = p + q;
  int ans = big;
  rep(dy, y) rep(dq, q) {
    V<long long> r{x + dy, p + dq};
    V<long long> m{a, b};
    auto [rem, mod] = atcoder::crt(r, m);
    if (mod != 0) chmin(ans, rem);
  }
  return ans;
}

void Main() {
  ints(t);
  rep(t) {
    int ans = Solve();
    if (ans == big) {
      wt("infinity");
    } else {
      wt(ans);
    }
  }
}
