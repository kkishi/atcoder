#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(s);
  V<mint> dp(s + 1);
  rep(i, 3, s + 1) {
    dp[i] = 1;
    for (int j = 3; i - j >= 3; ++j) dp[i] += dp[i - j];
  }
  wt(dp[s]);
}
