#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  strings(s);
  reverse(s);
  int n = sz(s);
  V<int> cnt(n + 1);
  rrep(i, n) cnt[i] = cnt[i + 1] + (s[i] == '?');
  vector cnt2(n + 1, vector(26, int(0)));
  rrep(i, n) rep(j, 26) cnt2[i][j] = cnt2[i + 1][j] + (s[i] == 'A' + j);
  vector dp(n + 1, vector(2, mint(0)));
  dp[0][0] = 1;
  auto f = [&](int i) -> mint {
    int ma = 0;
    int rem = 0;
    each(e, cnt2[i]) {
      chmax(ma, e);
      if (e == 0) ++rem;
    }
    int c = cnt[i];
    mint ok = 0;
    if (ma < 2) {
      rep(j, min(rem, c) + 1) {
        ok += mint::Comb(rem, j) * mint::Comb(c, j) * mint::Fact(j) *
              mint(26).Pow(c - j);
      }
    }
    return mint(52).Pow(c) - ok;
  };
  mint ng = 0;
  rep(i, n) {
    {
      mint d = dp[i][0];
      if (islower(s[i])) dp[i + 1][0] += d;
      if (isupper(s[i])) dp[i + 1][1] += d;
      if (s[i] == '?') rep(j, 2) dp[i + 1][j] += d * 26;
    }
    {
      mint d = dp[i][1];
      if (islower(s[i])) {
        dbg(d * f(i + 1));
        ng += d * f(i + 1);
      }
      if (isupper(s[i])) dp[i + 1][1] += d;
      if (s[i] == '?') {
        ng += d * f(i + 1) * 26;
        dp[i + 1][1] += d * 26;
      }
    }
  }
  wt(mint(52).Pow(cnt[0]) - ng);
}
