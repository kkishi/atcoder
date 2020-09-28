#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n, m);
  DisjointSet ds(n);
  rep(m) {
    ints(a, b);
    ds.Union(a - 1, b - 1);
  }
  set<int> s;
  rep(i, n) s.insert(ds.Find(i));
  wt(s.size() - 1);
}
