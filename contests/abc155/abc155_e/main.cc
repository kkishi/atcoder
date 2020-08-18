#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(N);
  VV<ll> dp(N.size() + 1, V<ll>(2));

  dp[0][0] = 0;
  dp[0][1] = 1;
  rep(i, N.size()) {
    int digit = N[i] - '0';
    dp[i + 1][0] =
        min({dp[i][0] + digit, dp[i][1] + (10 - digit), dp[i][1] + 1 + digit});
    dp[i + 1][1] = min(dp[i][0] + 1 + (9 - digit), dp[i][1] + (9 - digit));
  }
  wt(*min_element(all(dp[N.size()])));
}
