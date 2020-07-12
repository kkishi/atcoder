#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

using ll = long long;
const ll INF = 1LL<<60;

void setmin(ll& a, ll b) {
  if (a > b) a = b;
}

int main() {
  ll n, K;
  cin >> n >> K;
  vector<ll> h(n + 1);
  rep(i, n) cin >> h[i + 1];

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) rep(j, n) rep(k, i) {
    setmin(dp[i][j + 1], dp[k][j] + max(0LL, h[i] - h[k]));
  }
  ll ans = INF;
  rep(i, n + 1) setmin(ans, dp[i][n - K]);
  cout << ans << endl;
}
