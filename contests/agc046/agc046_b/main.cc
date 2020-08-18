#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<998244353>;

using namespace std;

int main() {
  ints(a, b, c, d);
  VV<mint> dp(c + 2, V<mint>(d + 2));
  dp[a][b] = 1;
  for (int i = a; i <= c; ++i) {
    for (int j = b; j <= d; ++j) {
      dp[i][j] -= dp[i - 1][j - 1] * (i - 1) * (j - 1);
      dp[i + 1][j] += dp[i][j] * j;
      dp[i][j + 1] += dp[i][j] * i;
    }
  }
  wt(dp[c][d]);
}
