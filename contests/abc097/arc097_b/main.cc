#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n, m);
  V<int> p(n);
  cin >> p;
  DisjointSet ds(n);
  rep(i, m) {
    ints(x, y);
    ds.Union(x - 1, y - 1);
  }
  int ans = 0;
  rep(i, n) if (ds.Same(i, p[i] - 1))++ ans;
  wt(ans);
}
