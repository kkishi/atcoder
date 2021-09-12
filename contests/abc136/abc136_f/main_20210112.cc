#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"
#include "compressor.h"
#include "modint.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  auto f = [](const V<int>& v) {
    Compressor c(v);
    V<int> ret;
    each(vi, v) ret.pb(c(vi));
    return ret;
  };
  x = f(x), y = f(y);
  V<tuple<int, int, int>> v;
  rep(i, n) v.eb(x[i], y[i], i);
  sort(all(v));

  // 1|0
  // -.-
  // 2|3
  vector cnt(n, V<int>(4));
  {
    BIT<int> bit(n);
    for (auto [_, y, i] : v) {
      cnt[i][2] = bit.Sum(y);
      cnt[i][1] = bit.Sum(n - 1) - cnt[i][2];
      bit.Add(y, 1);
    }
  }
  reverse(all(v));
  {
    BIT<int> bit(n);
    for (auto [_, y, i] : v) {
      cnt[i][3] = bit.Sum(y);
      cnt[i][0] = bit.Sum(n - 1) - cnt[i][3];
      bit.Add(y, 1);
    }
  }

  using mint = ModInt<998244353>;
  mint ans = 0;
  each(c, cnt) {
    V<mint> t;
    rep(i, 4) t.pb(c[i] == 0 ? 0 : (mint(2).Pow(c[i]) - 1));
    ans += mint(2).Pow(n - 1);
    ans += t[0] * t[1] * t[2] * t[3];
    ans += t[0] * t[1] * t[2];
    ans += t[0] * t[1] * t[3];
    ans += t[0] * t[2] * t[3];
    ans += t[0] * t[2];
    ans += t[1] * t[2] * t[3];
    ans += t[1] * t[3];
  }
  wt(ans);
}
