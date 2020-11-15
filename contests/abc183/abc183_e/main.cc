#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  vector dp(h, vector(w, mint(0)));
  vector rdp(h, vector(w, mint(0)));
  vector cdp(h, vector(w, mint(0)));
  vector rcdp(h, vector(w, mint(0)));
  dp[0][0] = 1;
  rep(i, h) rep(j, w) if (s[i][j] != '#') {
    if (i > 0 && j > 0) dp[i][j] += rcdp[i - 1][j - 1];
    if (i > 0) dp[i][j] += rdp[i - 1][j];
    if (j > 0) dp[i][j] += cdp[i][j - 1];

    rdp[i][j] = cdp[i][j] = rcdp[i][j] = dp[i][j];
    if (i > 0 && j > 0) rcdp[i][j] += rcdp[i - 1][j - 1];
    if (i > 0) rdp[i][j] += rdp[i - 1][j];
    if (j > 0) cdp[i][j] += cdp[i][j - 1];
  }
  wt(dp[h - 1][w - 1]);
}
