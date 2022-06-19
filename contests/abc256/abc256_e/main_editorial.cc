#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  V<int> x(n), c(n);
  cin >> x >> c;
  each(e, x)-- e;

  DisjointSet ds(n);
  int ans = 0;
  rep(i, n) {
    if (ds.Same(i, x[i])) {
      int j = i;
      int mi = big;
      do {
        chmin(mi, c[j]);
        j = x[j];
      } while (j != i);
      ans += mi;
    } else {
      ds.Union(i, x[i]);
    }
  }
  wt(ans);
}
