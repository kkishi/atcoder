#include <bits/stdc++.h>

#include "compress.h"
#include "macros.h"
#include "setmin.h"

using namespace std;

const ll INF = 1LL << 60;

int main() {
  rd(ll, n, K);
  vector<ll> h(n);
  cin >> h;

  h.push_back(0);
  vector<ll> hc = Compress(h);

  vector<vector<vector<ll>>> dp(
      n + 1, vector<vector<ll>>(K + 1, vector<ll>(hc.size(), INF)));
  dp[0][0][0] = 0;
  rep(i, n) rep(j, K + 1) rep(k, hc.size()) {
    if (j < K) {
      Setmin(dp[i + 1][j + 1][k], dp[i][j][k]);
    }
    Setmin(dp[i + 1][j][Uncompress(hc, h[i])],
           dp[i][j][k] + max(0LL, h[i] - hc[k]));
  }
  ll ans = INF;
  rep(i, K + 1) rep(j, hc.size()) Setmin(ans, dp[n][i][j]);
  wt(ans);
}
