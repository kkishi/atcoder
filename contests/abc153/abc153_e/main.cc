#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

const ll INF = 1LL << 50;
ll A[1000], B[1000];
ll dp[20001];

int main() {
  rd(ll, H, N);
  rep(i, N) cin >> A[i] >> B[i];
  rep(i, 20000 + 1) dp[i] = INF;
  dp[0] = 0;
  ll ans = INF;
  for (int i = 0; i <= H; ++i) {
    for (int n = 0; n < N; ++n) {
      ll j = i + A[n];
      dp[j] = min(dp[j], dp[i] + B[n]);
      if (j >= H) ans = min(ans, dp[j]);
    }
  }
  wt(ans);
}
