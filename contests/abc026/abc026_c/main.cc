#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> b(n);
  rep(i, 1, n) cin >> b[i];
  V<optional<int>> dp(n);
  wt(Fix([&](auto rec, int i) -> int {
    auto& d = dp[i];
    if (!d) {
      V<int> v;
      rep(j, n) if (j != i && b[j] - 1 == i) v.pb(rec(j));
      if (v.empty()) {
        d = 1;
      } else {
        auto [mi, ma] = minmax_element(all(v));
        d = *mi + *ma + 1;
      }
    }
    return *d;
  })(0));
}
