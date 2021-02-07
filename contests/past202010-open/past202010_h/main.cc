#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, M, K);
  V<string> s(N);
  cin >> s;
  int ans = 0;
  rep(x, 10) {
    rep(r, N) rep(c, M) rep(n, 1, min(N - r, M - c) + 1) {
      int ch = 0;
      rep(i, n) rep(j, n) if (s[r + i][c + j] - '0' != x)++ ch;
      if (ch <= K) {
        chmax(ans, n);
      }
    }
  }
  wt(ans);
}
