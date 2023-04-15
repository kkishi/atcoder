#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  DisjointSet ds(n);
  int ans = 0;
  rep(m) {
    ints(a, b);
    --a, --b;
    if (ds.Same(a, b)) ++ans;
    ds.Union(a, b);
  }
  wt(ans);
}
