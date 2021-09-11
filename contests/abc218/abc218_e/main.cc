#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  using T = tuple<int, int, int>;
  V<T> v;
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
  sort(all(v));
  int ans = 0;
  for (auto [c, a, b] : v) {
    ans += c;
    if (!ds.Same(a, b)) {
      ds.Union(a, b);
      ans -= c;
    }
  }
  wt(ans);
}
