#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, k);
  V<tuple<int, int, int>> es;
  rep(m) {
    ints(a, b, c);
    --a, --b;
    es.eb(a, b, c);
  }
  V<int> dp(n, big);
  dp[0] = 0;
  rep(k) {
    ints(e);
    --e;
    auto [a, b, c] = es[e];
    chmin(dp[b], dp[a] + c);
  }
  if (dp[n - 1] == big) {
    wt(-1);
  } else {
    wt(dp[n - 1]);
  }
}
