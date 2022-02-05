#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, q);
  DisjointSet ds(n + 1);
  rep(q) {
    ints(l, r);
    ds.Union(l - 1, r);
  }
  wt(ds.Same(0, n));
}
