#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "geometry.h"

using P = Vector<double>;
using C = Circle<double>;

void Main() {
  ints(n, m);
  V<P> p(n);
  cin >> p;
  V<C> c(m);
  rep(i, m) cin >> c[i].center >> c[i].radius;
  V<tuple<double, int, int>> e;
  auto d = [](const P& a, const P& b) { return (a - b).Norm(); };
  rep(i, n) rep(j, n) { e.eb(d(p[i], p[j]), i, j); }
  rep(i, n) rep(j, m) {
    e.eb(abs(d(p[i], c[j].center) - c[j].radius), i, n + j);
  }
  rep(i, m) rep(j, m) {
    double cd = d(c[i].center, c[j].center);
    double dist;
    auto contains = [&](const C& a, const C& b) {
      return cd + b.radius <= a.radius;
    };
    auto overlap = [&](const C& a, const C& b) {
      return cd <= a.radius + b.radius;
    };
    if (contains(c[i], c[j])) {
      dist = c[i].radius - (cd + c[j].radius);
    } else if (contains(c[j], c[i])) {
      dist = c[j].radius - (cd + c[i].radius);
    } else if (overlap(c[i], c[j])) {
      dist = 0;
    } else {
      dist = cd - (c[i].radius + c[j].radius);
    }
    e.eb(dist, n + i, n + j);
  }
  sort(e);

  double ans = big;
  rep(mask, 1 << m) {
    DisjointSet ds(n + m);
    double sum = 0;
    for (auto [dist, i, j] : e) {
      if (ds.Same(i, j)) continue;
      if (i >= n && hasbit(mask, i - n)) continue;
      if (j >= n && hasbit(mask, j - n)) continue;
      ds.Union(i, j);
      sum += dist;
    }
    chmin(ans, sum);
  }
  wt(ans);
}
