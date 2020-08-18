#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n, m);
  V<int> f(n);
  cin >> f;

  V<int> seen(m + 1);
  V<int> left(n);
  int curr = 0;
  rep(i, n) {
    chmax(curr, seen[f[i]]);
    left[i] = curr;
    seen[f[i]] = i + 1;
  }

  V<mint> dp(n + 1);
  dp[0] = 1;
  V<mint> dp_sum(n + 1);
  rep(i, n) {
    /*
    for (int j = left[i]; j <= i; ++j) {
      dp[i + 1] += dp[j];
    }
    */
    dp_sum[i] = dp[i] + (i == 0 ? 0 : dp_sum[i - 1]);
    dp[i + 1] = dp_sum[i] - (left[i] == 0 ? 0 : dp_sum[left[i] - 1]);
  }
  wt(dp[n]);
}
