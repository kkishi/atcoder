#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> a(n);
  cin >> a;
  int ans = 0;
  rep(i0, n) rep(j0, n) rep(i, -1, 2) rep(j, -1, 2) {
    if (i == 0 && j == 0) continue;
    int I = i0, J = j0;
    int x = 0;
    rep(n) {
      x *= 10;
      x += a[I][J] - '0';
      I = ((I + i) + n) % n;
      J = ((J + j) + n) % n;
    }
    chmax(ans, x);
  }
  wt(ans);
}
