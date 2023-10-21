#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(k);
  int n = sz(s);
  vector dp(n + 1, vector(n + 1, vector(2, big)));
  wt(Fix([&](auto rec, int l, int r, int can_delete_k) -> int {
    if (l >= r) return 0;
    int& ans = dp[l][r][can_delete_k];
    if (ans == big) {
      if (can_delete_k) {
        rep(del, min(r - l, k) + 1) chmin(ans, rec(l + del, r, false));
      } else {
        chmin(ans, 1 + rec(l + 1, r, false));
        if (s[l] == 'o') {
          rep(mid, l + 1, r) if (s[mid] == 'f' && rec(l + 1, mid, false) == 0) {
            chmin(ans, rec(mid + 1, r, true));
          }
        }
      }
    }
    return ans;
  })(0, n, false));
}
