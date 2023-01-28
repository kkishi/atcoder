#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "graph.h"

bool Solve() {
  ints(n, m);
  if (m != n - 1) return false;
  DisjointSet ds(n);
  rep(m) {
    ints(u, v);
    ds.Union(u - 1, v - 1);
  }
  return ds.Size(0) == n;
}

void Main() { wt(Solve()); }
