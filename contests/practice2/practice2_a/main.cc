#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n, q);
  DisjointSet ds(n);
  rep(q) {
    ints(t, u, v);
    if (t == 0) {
      ds.Union(u, v);
    } else {
      wt(ds.Same(u, v) ? 1 : 0);
    }
  }
}
