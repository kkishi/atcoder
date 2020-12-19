#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"
#include "geometry.h"

using Vec = Vector<double>;

void Main() {
  ints(n, m);
  int nm = n + m;
  V<Vec> xy(nm);
  V<int> c(nm);
  rep(i, nm) cin >> xy[i] >> c[i];

  V<tuple<double, int, int>> v;
  rep(i, nm - 1) rep(j, i + 1, nm)
      v.push_back({(xy[i] - xy[j]).Norm() * (c[i] == c[j] ? 1 : 10), i, j});
  sort(all(v));

  double ans = numeric_limits<double>::max();
  rep(s, 1 << m) {
    V<bool> use(nm);
    rep(i, nm) use[i] = (i < n) ? true : ((s >> (i - n)) & 1);
    DisjointSet ds(nm);
    double sum = 0;
    for (auto [c, i, j] : v) {
      if (!use[i] || !use[j]) continue;
      if (ds.Same(i, j)) continue;
      ds.Union(i, j);
      sum += c;
    }
    chmin(ans, sum);
  }
  wt(ans);
}
