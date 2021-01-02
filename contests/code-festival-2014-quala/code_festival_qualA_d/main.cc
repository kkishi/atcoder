#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, K);
  V<int> v;
  for (int x = a; x; x /= 10) {
    v.push_back(x % 10);
  }
  reverse(all(v));
  int ans = big;
  rep(i, sz(v)) rep(j, 10) rep(k, 10) {
    V<int> u = v;
    u[i] = j;
    rep(l, i + 1, sz(v)) u[l] = k;
    if (u[0] == 0) u = V<int>(u.begin() + 1, u.end());
    if (sz(set(all(u))) <= K) {
      int x = 0;
      rep(i, sz(u))(x *= 10) += u[i];
      chmin(ans, abs(a - x));
    }
  }
  wt(ans);
}
