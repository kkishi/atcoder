#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  strings(s);
  VV<mint> dp(100001, V<mint>(13));
  dp[0][0] = 1;
  rep(i, s.size()) {
    if (s[i] == '?') {
      rep(j, 10) rep(k, 13) dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
    } else {
      rep(j, 13) dp[i + 1][(j * 10 + s[i] - '0') % 13] += dp[i][j];
    }
  }
  wt(dp[s.size()][5]);
}
