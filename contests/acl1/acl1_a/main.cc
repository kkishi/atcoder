#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n);
  V<tuple<int, int, int>> xy;
  rep(i, n) {
    ints(x, y);
    xy.push_back({x, y, i});
  }
  sort(all(xy));

  DisjointSet ds(n);
  set<pair<int, int>> s;
  for (auto [_, y, j] : xy) {
    auto it = s.begin();
    auto jt = s.lower_bound({y, 0});
    if (it == jt) {
      s.insert({y, j});
    } else {
      for (auto kt = it; kt != jt; ++kt) {
        ds.Union(kt->second, j);
      }
      s.erase(next(it), jt);
    }
  }
  rep(i, n) wt(ds.Size(i));
}
