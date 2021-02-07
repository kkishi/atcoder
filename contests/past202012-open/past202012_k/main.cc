#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int board = 0;
  auto bit = [](int r, int c) { return 1 << ((r * 4) + c); };
  rep(i, 4) {
    strings(s);
    rep(j, 4) if (s[j] == '#') board |= bit(i, j);
  }
  V<optional<double>> dp(1 << 16);
  wt(Fix([&](auto rec, int state) -> double {
    if ((board & state) == board) return 0;
    auto& d = dp[state];
    if (d) return *d;
    d = big;
    rep(r, 4) rep(c, 4) {
      int dr[] = {1, 0, -1, 0, 0};
      int dc[] = {0, 1, 0, -1, 0};
      int same = 0;
      double sum = 0;
      rep(d, 5) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (0 <= nr && nr < 4 && 0 <= nc && nc < 4) {
          int nstate = state | bit(nr, nc);
          if (nstate == state) {
            ++same;
          } else {
            sum += rec(nstate);
          }
        } else {
          ++same;
        }
      }
      if (same == 5) continue;
      chmin(d, (5 + sum) / (5 - same));
    }
    return *d;
  })(0));
}
