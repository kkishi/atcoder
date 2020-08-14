#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

const ll INF = 1LL << 60;

int main() {
  ll n, K;
  cin >> n >> K;
  vector<ll> h(n + 1);
  rep(i, n) cin >> h[i + 1];

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) rep(j, n) rep(k, i) {
      chmin(dp[i][j + 1], dp[k][j] + max(0LL, h[i] - h[k]));
    }
  ll ans = INF;
  rep(i, n + 1) chmin(ans, dp[i][n - K]);
  cout << ans << endl;
}
