#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

void setmax(ll& a, ll b) {
  if (a < b) a = b;
}

int main() {
  rd(ll, n);
  vector<pair<ll, ll>> ai(n);
  rep(i, n) {
    cin >> ai[i].first;
    ai[i].second = i;
  }
  sort(all(ai), greater());
  vector<vector<ll>> dp(n + 1, vector(n + 1, 0LL));
  rep(i, n) rep(j, i + 1) {
    auto [a, index] = ai[i];
    setmax(dp[i + 1][j + 1], dp[i][j] + a * abs(index - j));
    setmax(dp[i + 1][j], dp[i][j] + a * abs(index - (n - 1 - (i - j))));
  }
  ll ans = 0;
  rep(i, n + 1) setmax(ans, dp[n][i]);
  wt(ans);
}
