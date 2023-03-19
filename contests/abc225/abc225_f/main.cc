#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<string> s(n);
  cin >> s;
  sort(all(s), [](const string& s, const string& t) { return s + t < t + s; });
  vector dp(n + 1, vector(n + 1, string("")));
  rrep(i, n) rep(j, n) {
    auto update = [](string& s, const string& t) {
      if (s == "" || (t != "" && s > t)) s = t;
    };
    update(dp[i][j], dp[i + 1][j]);
    // Prevent transitions from invalid states (empty strings with non-zero
    // used-words).
    if (dp[i + 1][j] != "" || j == 0) {
      update(dp[i][j + 1], s[i] + dp[i + 1][j]);
    }
  }
  wt(dp[0][k]);
}
