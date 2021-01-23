#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(n, m, k);
  V<bool> ng(n + 1);
  rep(k) {
    ints(a);
    ng[a] = true;
  }
  auto add = [](double a, double b) { return a + b; };
  SegmentTree<double> a(n + 1, add), b(n + 1, add);
  rrep(i, n + 1) {
    if (ng[i]) {
      b.Set(i, 1);
      continue;
    }
    if (i == n) {
      continue;
    }
    int l = i + 1;
    int r = min(i + 1 + m, n + 1);
    double A = 1 + a.Aggregate(l, r) / m;
    double B = b.Aggregate(l, r) / m;
    if (B == 1) {
      wt(-1);
      return;
    }
    a.Set(i, A);
    b.Set(i, B);
  }
  wt(a.Get(0) / (1 - b.Get(0)));
}
