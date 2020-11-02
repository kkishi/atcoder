#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;
mint dp[3001][3001];

void Main() {
  ints(N, S);
  V<int> A(N);
  cin >> A;

  dp[0][0] = 1;
  mint ans = 0;
  rep(i, N) {
    rep(j, S + 1) {
      dp[i + 1][j] += dp[i][j];
      if (int nj = j + A[i]; nj <= S) {
        mint added = j == 0 ? i + 1 : dp[i][j];
        dp[i + 1][nj] = added;
        if (nj == S) {
          ans += added * (N - i);
        }
      }
    }
  }
  wt(ans);
}
