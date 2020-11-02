#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> memo(n + 1, -1);
  wt(Fix([&](auto rec, int x) -> int {
    if (x == 0) return 0;
    if (memo[x] == -1) {
      int mini = numeric_limits<int>::max();
      chmin(mini, 1 + rec(x - 1));
      for (int i = 6; i <= x; i *= 6) {
        chmin(mini, 1 + rec(x - i));
      }
      for (int i = 9; i <= x; i *= 9) {
        chmin(mini, 1 + rec(x - i));
      }
      memo[x] = mini;
    }
    return memo[x];
  })(n));
}
