#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<tuple<int, int, int, int>> b;
  rep(n) {
    ints(w, s, v);
    b.eb(s + w, w, s, v);
  }
  sort(b);
  V<int> dp(20001, -1);
  dp[0] = 0;
  for (auto [_, w, s, v] : b) {
    for (int i = s; i >= 0; --i) {
      if (dp[i] == -1) continue;
      chmax(dp[i + w], dp[i] + v);
    }
  }
  wt(max(dp));
}
