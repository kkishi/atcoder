#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

int main() {
  rd(int, n, m);
  vector<bool> broken(n + 1);
  rep(i, m) {
    rd(int, a);
    broken[a] = true;
  }
  vector<mint> dp(n + 2);
  dp[0] = 1;
  rep(i, n) {
    if (broken[i]) continue;
    dp[i + 1] += dp[i];
    dp[i + 2] += dp[i];
  }
  wt(dp[n]);
}
