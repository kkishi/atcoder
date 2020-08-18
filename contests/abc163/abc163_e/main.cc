#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  vector<pair<ll, ll>> ai(n);
  rep(i, n) {
    cin >> ai[i].first;
    ai[i].second = i;
  }
  sort(all(ai), greater());
  VV<ll> dp(n + 1, V<ll>(n + 1));
  rep(i, n) rep(j, i + 1) {
    auto [a, index] = ai[i];
    chmax(dp[i + 1][j + 1], dp[i][j] + a * abs(index - j));
    chmax(dp[i + 1][j], dp[i][j] + a * abs(index - (n - 1 - (i - j))));
  }
  wt(*max_element(all(dp[n])));
}
