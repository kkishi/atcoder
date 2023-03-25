#include <bits/stdc++.h>

#include "atcoder.h"

int Solve(const string& s, int x) {
  V<int> v;
  each(e, to_string(x)) v.eb(e - '0');
  int n = sz(v);
  int m = sz(s);
  vector dp(n + 1, vector(m + 1, vector(2, vector(2, int(0)))));
  dp[0][0][0][0] = 1;
  rep(vi, n) rep(si, m + 1) rep(nz, 2) rep(lt, 2) {
    int dps = dp[vi][si][nz][lt];
    if (dps == 0) continue;
    rep(digit, 10) {
      if (!lt && digit > v[vi]) continue;
      int nnz = nz | (digit > 0);
      int nlt = lt | (digit < v[vi]);
      if (si == m) {
        // The condition is already met. Any digit is OK.
        dp[vi + 1][m][nnz][nlt] += dps;
      } else {
        if (nnz && digit == s[si] - '0') {
          // Start or continue.
          dp[vi + 1][si + 1][nnz][nlt] += dps;
        }
        // Don't start.
        if (si == 0) dp[vi + 1][0][nnz][nlt] += dps;
      }
    }
  }
  int ans = 0;
  each(e, dp[n][m]) each(e, e) ans += e;
  return ans;
}

void Main() {
  ints(t);
  rep(t) {
    strings(s);
    ints(l, r);
    wt(Solve(s, r) - Solve(s, l - 1));
  }
}
