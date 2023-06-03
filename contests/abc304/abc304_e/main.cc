#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  DisjointSet ds(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    ds.Union(u, v);
  }
  set<pair<int, int>> ng;
  ints(k);
  rep(k) {
    ints(x, y);
    --x, --y;
    x = ds.Find(x);
    y = ds.Find(y);
    assert(x != y);
    if (x > y) swap(x, y);
    ng.insert({x, y});
  }
  ints(q);
  rep(q) {
    ints(p, q);
    --p, --q;
    p = ds.Find(p);
    q = ds.Find(q);
    if (p > q) swap(p, q);
    wt(ng.count({p, q}) == 0);
  }
}
