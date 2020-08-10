#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

int a[3000];

using modint = ModInt<998244353>;

int main() {
  rd(int, n, s);
  rep(i, n) cin >> a[i];
  vector<modint> dp(s + 1);
  modint ans = 0;
  rep(i, n) {
    dp[0] += 1;
    vector<modint> next = dp;
    for (int j = 0; j <= s; ++j) {
      int k = j + a[i];
      if (k <= s) {
        next[k] += dp[j];
      }
    }
    swap(dp, next);
    ans += dp[s];
  }
  wt(ans);
}
