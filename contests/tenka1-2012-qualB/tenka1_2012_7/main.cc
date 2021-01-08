#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n), e(n);
  rep(i, n) cin >> s[i] >> e[i];

  vector overlap(n, vector(n, false));
  rep(i, n) rep(j, n) {
    auto intervals = [](string s, string e) {
      V<pair<string, string>> v;
      if (e <= "24:00") {
        v.eb(s, e);
      } else {
        v.eb(s, "24:00");
        e[0] -= 2;
        e[1] -= 4;
        if (e[1] < '0') {
          e[0] -= 1;
          e[1] += 10;
        }
        v.eb("00:00", e);
      }
      return v;
    };
    for (auto [si, ei] : intervals(s[i], e[i])) {
      for (auto [sj, ej] : intervals(s[j], e[j])) {
        if (ei <= sj || ej <= si) continue;
        overlap[i][j] = true;
      }
    }
  }

  V<int> dp(1 << n, big);
  rep(s, 1 << n) {
    bool ok = true;
    rep(i, n - 1) if (hasbit(s, i)) {
      rep(j, i + 1, n) if (hasbit(s, j) && overlap[i][j]) ok = false;
    }
    if (ok) {
      dp[s] = 1;
    } else {
      for (int t = (s - 1) & s; t > 0; t = (t - 1) & s) {
        chmin(dp[s], dp[t] + dp[s ^ t]);
      }
    }
  }
  wt(dp[(1 << n) - 1]);
}
