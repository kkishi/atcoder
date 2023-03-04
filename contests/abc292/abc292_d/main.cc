#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  using P = pair<int, int>;
  V<P> es(m);
  cin >> es;
  each(e, es)-- e.first, --e.second;
  DisjointSet ds(n);
  each(e, es) ds.Union(e.first, e.second);
  V<int> nodes(n), edges(n);
  rep(i, n)++ nodes[ds.Find(i)];
  each(e, es)++ edges[ds.Find(e.first)];
  bool ok = true;
  rep(i, n) if (nodes[i] != edges[i]) ok = false;
  wt(ok);
}
