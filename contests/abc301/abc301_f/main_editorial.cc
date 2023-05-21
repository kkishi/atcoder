// This is 52 times faster than main_editorial_tle.cc, but is harder to read.
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
    char c = s[i];
    rep(j, 30) {
      mint d = dp[i][j];
      if (d == 0) continue;
      if (j == 0) {  // T = ""
        if (c == '?') {
          rep(k, 2) dp[i + 1][j + k] += d * 26;
        } else {
          dp[i + 1][j + isupper(c)] += d;
        }
      } else if (j <= 26) {  // T = "D"
        if (c == '?') {
          // lower
          dp[i + 1][j] += d * 26;
          int x = sz(seen);
          // upper (seen in S)
          dp[i + 1][27] += d * x;
          // upper (not seen in S)
          if (x < 26) {
            assert(j <= 26);
            assert(j >= x);
            mint p = mint(j - x) / (26 - x);
            dp[i + 1][27] += p * d * (26 - x);
            dp[i + 1][j + 1] += (1 - p) * d * (26 - x);
          }
        } else {
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
        }
      } else if (j == 27) {  // T = "DD"
        if (c == '?') {
          rep(k, 2) dp[i + 1][j + k] += d * 26;
        } else {
          dp[i + 1][j + islower(c)] += d;
        }
      } else if (j == 28) {  // T = "DDo
        if (c == '?') {
          rep(k, 2) dp[i + 1][j + k] += d * 26;
        } else {
          dp[i + 1][j + isupper(c)] += d;
        }
      } else {  // T = "DDoS"
        assert(j == 29);
        dp[i + 1][j] += d * (c == '?' ? 52 : 1);
      }
    }
    if (isupper(c)) seen.insert(c);
  }
  wt(accumulate(dp[n]) - dp[n][29]);
}
