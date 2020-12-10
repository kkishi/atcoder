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
        v.emplace_back(s, e);
      } else {
        v.emplace_back(s, "24:00");
        e[0] -= 2;
        e[1] -= 4;
        if (e[1] < '0') {
          e[0] -= 1;
          e[1] += 10;
        }
        v.emplace_back("00:00", e);
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

  V<int> dp(1 << n, numeric_limits<int>::max());
  rep(s, 1 << n) {
    bool ok = true;
    auto bit = [](int bits, int i) { return (bits >> i) & 1; };
    rep(i, n - 1) if (bit(s, i)) {
      rep(j, i + 1, n) if (bit(s, j) && overlap[i][j]) ok = false;
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
