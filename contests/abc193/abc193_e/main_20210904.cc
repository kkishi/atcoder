#include <bits/stdc++.h>

#include <atcoder/math>

#include "atcoder.h"

int Solve() {
  ints(x, y, p, q);
  int a = 2 * (x + y), b = p + q;
  int ans = big;
  rep(i, p, p + q) {
    auto [Y, Z] = atcoder::crt({x, i}, {a, b});
    if (Y != 0) chmin(ans, Y);
  }
  rep(i, x, x + y) {
    auto [Y, Z] = atcoder::crt({i, p}, {a, b});
    if (Y != 0) chmin(ans, Y);
  }
  return ans;
}

void Main() {
  ints(t);
  rep(i, t) {
    int ans = Solve();
    if (ans == big) {
      wt("infinity");
    } else {
      wt(ans);
    }
  }
}
