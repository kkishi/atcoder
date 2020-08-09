#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  vector<bool> dp(n * 100 + 1);
  dp[0] = true;
  rep(i, n) {
    for (int j = n * 100; j - p[i] >= 0; --j) {
      if (dp[j - p[i]]) dp[j] = true;
    }
  }
  int ans = 0;
  rep(i, n * 100 + 1) if (dp[i])++ ans;
  wt(ans);
}
