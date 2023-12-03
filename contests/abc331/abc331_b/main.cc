#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, s, m, l);
  int ans = big;
  rep(i, 100) rep(j, 100) rep(k, 100) {
    int x = i * 6 + j * 8 + k * 12;
    if (x >= n) chmin(ans, i * s + j * m + k * l);
  }
  wt(ans);
}
