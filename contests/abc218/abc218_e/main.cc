#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> v;
  DisjointSet ds(n);
  rep(m) {
    ints(a, b, c);
    --a, --b;
    if (c <= 0) {
      ds.Union(a, b);
    } else {
      v.eb(c, a, b);
    }
  }
  sort(v);
  int ans = 0;
  for (auto [c, a, b] : v) {
    if (!ds.Same(a, b)) {
      ds.Union(a, b);
    } else {
      ans += c;
    }
  }
  wt(ans);
}
