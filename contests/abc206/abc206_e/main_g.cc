#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l, r);
  int ans = 0;
  V<int> dp(r + 1);
  rrep(g, 2, r + 1) {
    int L = div_ceil(l, g);
    int H = r / g;
    int x = H - L + 1;
    int M = x * x;
    for (int i = g * 2; i <= r; i += g) {
      M -= dp[i];
    }
    dp[g] = M;
    ans += M;
    if (l <= g && g <= r) {
      ans -= x * 2 - 1;
    }
  }
  wt(ans);
}
