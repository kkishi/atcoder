#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  DisjointSet ds(n);
  rep(m) {
    ints(a, b);
    ds.Union(a - 1, b - 1);
  }
  int ans = 0;
  rep(i, n) chmax(ans, ds.Size(i));
  wt(ans);
}
