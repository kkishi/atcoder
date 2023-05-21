#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  strings(s);
  int n = sz(s);
  vector dp(n + 1, vector(30, mint(0)));
  dp[0][0] = 1;
  set<char> seen;
  rep(i, n) {
    auto process = [&](char c) {
      rep(j, 30) {
        mint d = dp[i][j];
        if (d == 0) continue;
        if (j == 0) {  // T = ""
          dp[i + 1][j + isupper(c)] += d;
        } else if (j <= 26) {  // T = "D"
          if (islower(c)) {
            dp[i + 1][j] += d;
          } else {
            if (seen.count(c)) {
              dp[i + 1][27] += d;
            } else {
              int x = sz(seen);
              assert(j <= 26);
              assert(j >= x);
              assert(x < 26);
              mint p = mint(j - x) / (26 - x);
              dp[i + 1][27] += p * d;
              dp[i + 1][j + 1] += (1 - p) * d;
            }
          }
        } else if (j == 27) {  // T = "DD"
          dp[i + 1][j + islower(c)] += d;
        } else if (j == 28) {  // T = "DDo
          dp[i + 1][j + isupper(c)] += d;
        } else {  // T = "DDoS"
          assert(j == 29);
          dp[i + 1][j] += d;
        }
      }
    };
    if (s[i] == '?') {
      rep(i, 26) {
        process('a' + i);
        process('A' + i);
      }
    } else {
      process(s[i]);
    }
    if (isupper(s[i])) seen.insert(s[i]);
  }
  wt(accumulate(dp[n]) - dp[n][29]);
}
