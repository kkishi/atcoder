#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, q);
  using T = tuple<int, int, int>;
  VV<T> v(n);
  rep(m) {
    ints(a, b, s, t);
    --a, --b;
    v[a].eb(s, t, b);
  }
  each(e, v) sort(e);
  using P = pair<int, int>;
  vector dbl(30, map<P, P>());
  P na = {-1, -1};
  rep(i, n) {
    rep(j, sz(v[i])) {
      auto [s, t, b] = v[i][j];
      auto it = lower_bound(all(v[b]), T{t, -1, -1});
      if (it == v[b].end()) {
        dbl[0][{i, j}] = na;
      } else {
        dbl[0][{i, j}] = {b, it - v[b].begin()};
      }
    }
  }
  rep(i, 29) {
    for (auto [k, v] : dbl[i]) {
      if (v != na) {
        if (dbl[i].count(v)) {
          v = dbl[i][v];
        } else {
          v = na;
        }
      }
      dbl[i + 1][k] = v;
    }
  }
  rep(q) {
    ints(x, y, z);
    --y;
    auto it = lower_bound(all(v[y]), T{x, -1, -1});
    if (it == v[y].end() || get<0>(*it) >= z) {
      wt(y + 1);
      continue;
    }
    P p = {y, it - v[y].begin()};
    rrep(i, 30) {
      P q = dbl[i][p];
      if (q != na) {
        auto [a, i] = q;
        if (get<0>(v[a][i]) < z) {
          p = q;
        }
      }
    }
    auto [a, i] = p;
    auto [s, t, b] = v[a][i];
    if (z <= s) {
      wt(a + 1);
    } else if (z <= t) {
      wt(a + 1, b + 1);
    } else {
      wt(b + 1);
    }
  }
}
