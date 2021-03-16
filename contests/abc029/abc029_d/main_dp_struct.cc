#include <bits/stdc++.h>

#include "atcoder.h"

struct DP {
  int cnt, one;
  void Add(DP x, int digit) {
    cnt += x.cnt;
    one += x.one + (digit == 1 ? x.cnt : 0);
  }
};

void Main() {
  ints(n);
  V<int> v;
  while (n) {
    v.pb(n % 10);
    n /= 10;
  }
  reverse(all(v));
  int N = sz(v);
  vector dp(N + 1, vector(2, DP{0, 0}));
  dp[0][0] = {1, 0};
  rep(i, N) rep(less, 2) rep(j, 10) {
    if (!less && j > v[i]) continue;
    dp[i + 1][less | (j < v[i])].Add(dp[i][less], j);
  }
  wt(dp[N][0].one + dp[N][1].one);
}
