#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Solve() {
  ints(n);
  strings(s);
  each(e, s) e -= 'A';
  int N = (n + 1) / 2;
  vector dp(N, vector(2, vector(26, mint(0))));
  rep(i, s[0]) dp[0][1][i] = 1;
  dp[0][0][s[0]] = 1;
  rep(i, 1, N) rep(less, 2) rep(j, 26) {
    mint x = dp[i - 1][less][j];
    if (x == 0) continue;
    rep(k, 26) {
      if (!less && k > s[i]) continue;
      int nless = less | (k < s[i]);
      dp[i][nless][k] += x;
    }
  }
  mint ans = accumulate(dp[N - 1][1]);
  {
    string head = s.substr(0, N);
    string tail = s.substr(0, n / 2);
    reverse(tail);
    if (head + tail <= s) {
      ans += accumulate(dp[N - 1][0]);
    }
  }
  wt(ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}
