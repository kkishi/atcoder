#include <bits/stdc++.h>

#include "atcoder.h"

using P = complex<double>;

double cross(const P& a, const P& b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

void Main() {
  ints(n);
  V<P> p;
  rep(n) {
    ints(x, y);
    p.eb(x, y);
  }
  int x = 0;
  int y = 0;
  const double pi = acos(-1);
  rep(i, n) {
    V<pair<double, P>> q;
    rep(j, n) if (j != i) {
      q.eb(arg(p[j] - p[i]), p[j]);
      q.eb(arg(p[j] - p[i]) + 2 * pi, p[j]);
    }
    auto less = [](auto& a, auto& b) { return a.first < b.first; };
    sort(q, less);
    rep(j, sz(q) / 2) {
      auto [theta, qj] = q[j];
      const double eps = 1e-10;
      auto it =
          lower_bound(all(q), pair<double, P>{theta + pi / 2 - eps, {}}, less);
      auto jt =
          lower_bound(all(q), pair<double, P>{theta + pi + eps, {}}, less);
      if (it == jt) continue;
      int cnt = jt - it;
      if (it != q.end() && cross(qj - p[i], it->second - p[i]) == 0) {
        ++x;
        --cnt;
      }
      y += cnt;
    }
  }
  int tot = n * (n - 1) * (n - 2) / 6;
  wt(tot - (x + y), x, y);
}
