#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> e;
  rep(i, n) {
    ints(c);
    e.emplace_back(c, i, n);
  }
  rep(m) {
    ints(a, b, r);
    --a, --b;
    e.emplace_back(r, a, b);
  }
  sort(all(e));
  DisjointSet ds(n + 1);
  int ans = 0;
  for (auto [c, a, b] : e) {
    if (!ds.Same(a, b)) {
      ans += c;
      ds.Union(a, b);
    }
  }
  wt(ans);
}
