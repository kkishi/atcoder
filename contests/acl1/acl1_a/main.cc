#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n);
  V<pair<int, int>> xy(n);
  rep(i, n) {
    ints(x, y);
    xy[x - 1] = {y, i};
  }

  DisjointSet ds(n);
  stack<pair<int, int>> s;
  for (auto [y, i] : xy) {
    int miny = y;
    while (!s.empty()) {
      auto [ty, ti] = s.top();
      if (ty > y) break;
      s.pop();
      chmin(miny, ty);
      ds.Union(i, ti);
    }
    s.push({miny, i});
  }
  rep(i, n) wt(ds.Size(i));
}
