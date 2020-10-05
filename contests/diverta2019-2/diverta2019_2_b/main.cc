#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  int ans = n;
  rep(i, 1, n) rep(j, i) {
    int p = x[i] - x[j];
    int q = y[i] - y[j];
    DisjointSet ds(n);
    int size = n;
    rep(k, 1, n) rep(l, k) if (x[k] + p == x[l] && y[k] + q == y[l] ||
                               x[l] + p == x[k] && y[l] + q == y[k]) {
      if (!ds.Same(k, l)) --size;
      ds.Union(k, l);
    }
    chmin(ans, size);
  }
  wt(ans);
}
