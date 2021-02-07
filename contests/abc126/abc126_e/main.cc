#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  DisjointSet ds(n);
  rep(i, m) {
    ints(x, y, z);
    ds.Union(x - 1, y - 1);
  }
  set<int> s;
  rep(i, n) s.insert(ds.Find(i));
  wt(s.size());
}
