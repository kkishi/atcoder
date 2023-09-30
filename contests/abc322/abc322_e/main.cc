#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"

void Main() {
  ints(n, k, p);
  int N = Pow(p + 1, k);
  vector dp(N, big);
  dp[0] = 0;
  rep(n) {
    ints(c);
    V<int> a(k);
    cin >> a;
    vector ndp = dp;
    rep(i, N) {
      V<int> v;
      int x = i;
      rep(j, k) {
        v.pb(min(p, x % (p + 1) + a[j]));
        x /= p + 1;
      }
      int ni = 0;
      rep(j, k) {
        ni *= p + 1;
        ni += v[k - 1 - j];
      }
      chmin(ndp[ni], dp[i] + c);
    }
    swap(dp, ndp);
  }
  int ans = dp[N - 1];
  if (ans == big) ans = -1;
  wt(ans);
}
