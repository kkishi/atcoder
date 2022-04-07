#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  vector dp(n + 1, mint(0));
  dp[0] = 1;
  vector sdp = dp;
  auto sum = [&](int i, int j) {
    // dp[i] + ... + dp[j]
    return sdp[j] - (i - 1 < 0 ? 0 : sdp[i - 1]);
  };
  V<tuple<int, int, mint>> u = {{big, -1, 0}}, d = {{-big, -1, 0}};
  rep(i, n) {
    {
      while (get<0>(u.back()) < a[i]) u.pop_back();
      auto [_, j, x] = u.back();
      x += a[i] * sum(j + 1, i);
      dp[i + 1] += x;
      u.eb(a[i], i, x);
    }
    {
      while (get<0>(d.back()) > a[i]) d.pop_back();
      auto [_, j, x] = d.back();
      x += a[i] * sum(j + 1, i);
      dp[i + 1] -= x;
      d.eb(a[i], i, x);
    }
    sdp[i + 1] = sdp[i] + dp[i + 1];
  }
  wt(dp[n]);
}
