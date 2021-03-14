#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s, x);
  each(e, s) e -= '0';
  V<int> ten(n);
  ten[n - 1] = 1;
  rrep(i, n - 1) ten[i] = ten[i + 1] * 10 % 7;
  V<int> mods(n);
  rep(i, n) mods[i] = s[i] * ten[i] % 7;
  vector dp(n, vector(7, false));
  auto taka = [&](int i) { return x[i] == 'T'; };
  rrep(i, n) {
    rep(mod, 7) {
      V<int> cand{mod, (mod + mods[i]) % 7};
      bool canwin = false;
      for (int c : cand) {
        if (i == n - 1) {
          if (taka(i) && c == 0) {
            canwin = true;
          }
          if (!taka(i) && c != 0) {
            canwin = true;
          }
        } else {
          if (taka(i) == taka(i + 1)) {
            if (dp[i + 1][c]) {
              canwin = true;
            }
          } else {
            if (!dp[i + 1][c]) {
              canwin = true;
            }
          }
        }
      }
      dp[i][mod] = canwin;
    }
  }
  bool takahashi;
  if (taka(0)) {
    takahashi = dp[0][0];
  } else {
    takahashi = !dp[0][0];
  }
  wt(takahashi ? "Takahashi" : "Aoki");
}
