#include <bits/stdc++.h>

#include "atcoder.h"

struct Res {
  int t, n;
  bool operator<(const Res& r) const { return t - n < r.t - r.n; };
  bool operator>(const Res& r) const { return t - n > r.t - r.n; };
};

void Main() {
  VV<int> b(2, V<int>(3));
  VV<int> c(3, V<int>(2));
  cin >> b >> c;
  map<V<string>, optional<Res>> dp;
  V<string> init(3, "   ");
  auto [t, n] = Fix([&](auto rec, int depth, V<string>& g) -> Res {
    if (depth == 9) {
      int t = 0, n = 0;
      rep(i, 2) rep(j, 3)(g[i][j] == g[i + 1][j] ? t : n) += b[i][j];
      rep(i, 3) rep(j, 2)(g[i][j] == g[i][j + 1] ? t : n) += c[i][j];
      return {t, n};
    }
    auto& d = dp[g];
    if (!d) {
      if (even(depth)) {
        d = {-big, 0};
        rep(i, 3) rep(j, 3) if (g[i][j] == ' ') {
          g[i][j] = 'o';
          chmax(d, rec(depth + 1, g));
          g[i][j] = ' ';
        }
      } else {
        d = {big, 0};
        rep(i, 3) rep(j, 3) if (g[i][j] == ' ') {
          g[i][j] = 'x';
          chmin(d, rec(depth + 1, g));
          g[i][j] = ' ';
        }
      }
    }
    return *d;
  })(0, init);
  wt(t);
  wt(n);
}
