#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  vector es(n, vector(2, int(0)));
  cin >> es;
  each(e, es) each(e, e)-- e;
  DisjointSet ds(n);
  each(e, es) ds.Union(e[0], e[1]);
  V<int> nodes(n), edges(n);
  rep(i, n)++ nodes[ds.Find(i)];
  each(e, es)++ edges[ds.Find(e[0])];
  bool ok = true;
  rep(i, n) if (nodes[i] != edges[i]) ok = false;
  wt(ok);
}
