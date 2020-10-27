#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(n);
  cin >> a >> b;
  DisjointSet ds(n);
  rep(m) {
    ints(c, d);
    --c, --d;
    ds.Union(c, d);
  }
  map<int, int> as, bs;
  rep(i, n) {
    int r = ds.Find(i);
    as[r] += a[i];
    bs[r] += b[i];
  }
  bool ok = true;
  rep(i, n) {
    int r = ds.Find(i);
    if (as[r] != bs[r]) ok = false;
  }
  wt(ok);
}
