#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "segment_tree.h"

void Main() {
  ints(n, m, d);
  V<pair<int, int>> xv(n);
  cin >> xv;
  sort(xv);
  V<int> x(n), v(n);
  rep(i, n) tie(x[i], v[i]) = xv[i];

  V<int> xs(all(x));
  xs.erase(unique(all(xs)), xs.end());

  wt(BinarySearch<int>(-1, big, [&](int mini) {
    SegmentTree<int> t(n, [](int a, int b) { return max(a, b); });
    rep(i, n) {
      if (v[i] < mini) continue;
      auto it = lower_bound(all(xs), x[i]);
      auto jt = lower_bound(all(xs), x[i] - d + 1);
      int agg = t.Aggregate(0, jt - xs.begin());
      t.Set(it - xs.begin(), agg + 1);
    }
    return t.Aggregate(0, n) >= m;
  }));
}
