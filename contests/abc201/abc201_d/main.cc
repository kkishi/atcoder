#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> a(h);
  cin >> a;
  rep(i, h) rep(j, w) {
    int s = a[i][j] == '+' ? 1 : -1;
    a[i][j] = s;
  }
  vector dp(h, vector(w, -big));
  int res = Fix([&](auto rec, int r, int c) -> int {
    if (dp[r][c] != -big) return dp[r][c];
    if (r == h - 1 && c == w - 1) {
      return 0;
    }
    int ret = -big;
    if (r < h - 1) chmax(ret, a[r + 1][c] - rec(r + 1, c));
    if (c < w - 1) chmax(ret, a[r][c + 1] - rec(r, c + 1));
    return dp[r][c] = ret;
  })(0, 0);
  wt(res > 0 ? "Takahashi" : res < 0 ? "Aoki" : "Draw");
}
