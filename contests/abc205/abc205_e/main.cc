#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

mint Naive(int n, int m, int k) {
  int N = n + m;
  vector dp(N + 1, vector(N + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, N) rep(w, i + 1) {
    int b = i - w;
    if (w + 1 <= n && w + 1 <= b + k) {
      dp[i + 1][w + 1] += dp[i][w];
    }
    if (b + 1 <= m) {
      dp[i + 1][w] += dp[i][w];
    }
  }
  mint ans = 0;
  rep(i, N + 1) ans += dp[N][i];
  return ans;
}

void Main() {
  int X = 4;
  rep(n, 10) {
    V<mint> v;
    rep(i, n) v.pb(Naive(i, n - i, X));
    dbg(n, v);
  }
  auto f = [](int n, int k, int l) -> mint {
    auto C = [](int a, int b) -> mint {
      if (b < 0) return 0;
      return mint::Comb(a, b);
    };
    {
      // It appears like it breaks when y is larger than x (z becomes negative).
      // Return 0 in such cases.
      int a = min(k, n - k);
      int b = k - 1 - l;
      chmin(b, n - b);
      if (a < b) return 0;
    }
    mint x = C(n, k);
    mint y = C(n, k - 1 - l);
    mint z = x - y;
    return z;
  };
  rep(n, 10) {
    V<mint> v;
    rep(k, n) v.pb(f(n, k, X));
    dbg(n, v);
  }

  ints(n, m, k);
  wt(f(n + m, n, k));
}
