#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, D, H);
  double ans = 0;
  rep(n) {
    rd(double, d, h);
    chmax(ans, h - d * (H - h) / (D - d));
  }
  wt(ans);
}
