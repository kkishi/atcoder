#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  VV<pair<int, int>> e(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    e[min(a, b)].eb(a, b);
  }
  DisjointSet ds(n);
  int cnt = 0;
  V<int> ans(n);
  rrep(i, n) {
    ans[i] = n - i - 1 - cnt;
    each(a, b, e[i]) {
      if (!ds.Same(a, b)) {
        ds.Union(a, b);
        ++cnt;
      }
    }
  }
  each(e, ans) wt(e);
}
