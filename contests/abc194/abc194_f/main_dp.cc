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

  // This calculates the same values with the calc function in main.cc, but
  // using DP (simpler code but worse computation time).
  vector dp(N + 1, vector(18, mint(0)));
  dp[0][k] = 1;
  rep(rem, 1, N + 1) rrep(used, 17) {
    dp[rem][used] =
        dp[rem - 1][used] * used + dp[rem - 1][used + 1] * (16 - used);
  }

  mint ans = 0;
  set<int> s;
  rep(i, N) {
    int rem = N - i - 1;
    // 1) Slots [0, i) are all 0. Slot i is smaller than the input, if i is 0,
    // otherwise slot i can be any digit. Slots [i+1, N) can be any digit.
    int maxi = i > 0 ? 16 : v[i];
    rep(j, 1, maxi) ans += dp[rem][1];
    // 2) Slots [0, i) are all same as the input. Slot i is smaller than the
    // input. Slots [i+1, N) can be any digit.
    if (i > 0) {
      rep(j, v[i]) {
        set<int> t(s);
        t.insert(j);
        ans += dp[rem][sz(t)];
      }
    }
    s.insert(v[i]);
  }
  // 3) If the input satisfies the condition without any change, increment ans.
  if (sz(s) == k) {
    ans += 1;
  }
  wt(ans);
}
