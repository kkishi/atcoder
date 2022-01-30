#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  const int B = m + 1;
  using A = array<int, 10>;
  auto enc = [&](const A& a) {
    V<int> v;
    int x = 0;
    rep(i, m) if (a[i] > x) {
      rep(a[i] - x) v.pb(i);
      x = a[i];
    }
    assert(sz(v) <= 3);
    while (sz(v) < 3) v.pb(m);
    return v[0] * B * B + v[1] * B + v[2];
  };
  auto dec = [&](int x) {
    V<int> v = {x / (B * B), x / B % B, x % B};
    A a{};
    int y = 0;
    rep(i, m) {
      rep(j, 3) if (v[j] == i)++ y;
      a[i] = y;
    }
    return a;
  };
  int L = B * B * B;
  vector dp(n, vector(L, mint(0)));
  rep(i, m) {
    A a{};
    rep(j, i, m) a[j] = 1;
    dp[0][enc(a)] = 1;
  }
  rep(i, 1, n) {
    rep(j, L) {
      mint d = dp[i - 1][j];
      if (d == 0) continue;
      A a = dec(j);
      rep(k, m) {
        A b = a;
        chmax(b[k], 1);
        rep(l, k) { chmax(b[k], a[l] + 1); }
        bool ok = true;
        rep(i, m) if (b[i] > 3) ok = false;
        if (ok) {
          dp[i][enc(b)] += d;
        }
      }
    }
  }
  mint ans = 0;
  rep(j, L) {
    A a = dec(j);
    bool ok = false;
    rep(i, m) if (a[i] == 3) ok = true;
    if (ok) ans += dp[n - 1][j];
  }
  wt(ans);
}
