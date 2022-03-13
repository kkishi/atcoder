#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  // Naive solution for debugging.
  /*
  map<int, optional<bool>> dp;
  wt(Fix([&](auto rec, int x) -> bool {
    if (x > n) return true;
    auto& d = dp[x];
    if (!d) {
      *d = !rec(x * 2) || !rec(x * 2 + 1);
    }
    return *d;
  })(1)
         ? "Takahashi"
         : "Aoki");
  */
  V<int> v;
  while (n) {
    v.pb(n & 1);
    n >>= 1;
  }
  reverse(v);
  string t = "Takahashi", a = "Aoki";
  if (even(sz(v) - 1)) {
    rep(i, 1, sz(v)) {
      if (i & 1) {
        if (v[i] == 0) {
          wt(t);
          return;
        }
      } else {
        if (v[i] == 1) {
          wt(a);
          return;
        }
      }
    }
    wt(a);
  } else {
    rep(i, 1, sz(v)) {
      if (i & 1) {
        if (v[i] == 1) {
          wt(t);
          return;
        }
      } else {
        if (v[i] == 0) {
          wt(a);
          return;
        }
      }
    }
    wt(t);
  }
}
