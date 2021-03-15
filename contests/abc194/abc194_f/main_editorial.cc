#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  strings(n);
  const int N = sz(n);
  V<int> v;
  each(e, n) {
    if (isdigit(e)) {
      v.pb(e - '0');
    } else {
      v.pb(e - 'A' + 10);
    }
  }
  ints(k);

  // Digit DP
  vector dp(N + 1, vector(18, mint(0)));
  set<int> st;
  rep(i, N) {
    rep(j, k + 1) {
      dp[i + 1][j] += dp[i][j] * j;
      dp[i + 1][j + 1] += dp[i][j] * (16 - j);
    }
    if (i == 0) {
      dp[1][1] += v[0] - 1;
    } else {
      dp[i + 1][1] += 15;
      rep(k, v[i]) dp[i + 1][sz(st) + 1 - st.count(k)] += 1;
    }
    st.insert(v[i]);
  }
  mint ans = dp[N][k];
  if (sz(st) == k) ++ans;
  wt(ans);
}
