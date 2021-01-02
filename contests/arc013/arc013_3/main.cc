#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int grundy = 0;
  rep(n) {
    V<int> x(3);
    cin >> x;
    ints(m);
    V<int> lo(3, big);
    V<int> hi(3, -big);
    rep(m) {
      V<int> v(3);
      cin >> v;
      rep(i, 3) {
        chmin(lo[i], v[i]);
        chmax(hi[i], v[i]);
      }
    }
    rep(i, 3) {
      grundy ^= lo[i];
      grundy ^= x[i] - 1 - hi[i];
    }
  }
  wt(grundy == 0 ? "LOSE" : "WIN");
}
