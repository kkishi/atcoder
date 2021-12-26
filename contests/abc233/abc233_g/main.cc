#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  vector dp(n + 1, vector(n + 1, vector(n + 1, vector(n + 1, int(-1)))));
  wt(Fix([&](auto rec, int a, int b, int c, int d) -> int {
    int& ret = dp[a][b][c][d];
    if (ret == -1) {
      ret = [&]() -> int {
        if (a == b || c == d) return 0;
        {
          bool ok = true;
          rep(i, a, b) if (s[i][c] == '#') ok = false;
          if (ok) return rec(a, b, c + 1, d);
        }
        {
          bool ok = true;
          rep(i, a, b) if (s[i][d - 1] == '#') ok = false;
          if (ok) return rec(a, b, c, d - 1);
        }
        {
          bool ok = true;
          rep(i, c, d) if (s[a][i] == '#') ok = false;
          if (ok) return rec(a + 1, b, c, d);
        }
        {
          bool ok = true;
          rep(i, c, d) if (s[b - 1][i] == '#') ok = false;
          if (ok) return rec(a, b - 1, c, d);
        }
        int ret = max(b - a, d - c);
        rep(i, a + 1, b) chmin(ret, rec(a, i, c, d) + rec(i, b, c, d));
        rep(i, c + 1, d) chmin(ret, rec(a, b, c, i) + rec(a, b, i, d));
        return ret;
      }();
    }
    return ret;
  })(0, n, 0, n));
}
