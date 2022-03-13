#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, k);
  V<int> w(n);
  cin >> w;
  mint s = accumulate(all(w), mint(0));
  // Partition w into 3 subsets.
  int n3 = n / 3;
  V<int> cs = {0, n3, n3 * 2, n};
  VV<mint> W(3);
  V<mint> S(3);
  rep(i, 3) {
    rep(j, cs[i], cs[i + 1]) W[i].eb(w[j]);
    S[i] = accumulate(all(W[i]), mint(0));
  }
  auto f = [&](const V<mint>& w) {
    const int N = 50;
    int n = sz(w);
    mint s = accumulate(all(w), mint(0));
    // Optimze by not calling ModInt.Inv() in the heavy loop. Note that when
    // s=0, inv_s won't be used, so its value doesn't matter.
    mint inv_s = s == 0 ? 0 : 1 / s;
    vector dp(N + 1, vector(1 << n, mint(0)));
    dp[0][0] = 1;
    rep(i, N) rep(mask, 1 << n) rep(j, n) {
      dp[i + 1][mask | (1 << j)] += dp[i][mask] * w[j] * inv_s;
    }
    // p[i][j] is the conditional probability of getting j distinct items after
    // i draws within this subset.
    vector p(N + 1, vector(N + 1, mint(0)));
    rep(i, N + 1) rep(j, 1 << n) p[i][popcount(j)] += dp[i][j];
    return p;
  };
  vector P = {f(W[0]), f(W[1]), f(W[2])};
  mint ans = 0;
  rep(a, k + 1) rep(b, k + 1 - a) {
    int c = k - (a + b);
    // p is the probability of getting a items from W[0], b items from W[1] and
    // c items from W[2].
    mint p = 1;
    p *= (S[0] / s).Pow(a);
    p *= (S[1] / s).Pow(b);
    p *= (S[2] / s).Pow(c);
    p *= mint::Comb(k, b + c);
    p *= mint::Comb(b + c, b);
    rep(A, m + 1) rep(B, m + 1 - A) {
      int C = m - (A + B);
      ans += p * P[0][a][A] * P[1][b][B] * P[2][c][C];
    }
  }
  wt(ans);
}
