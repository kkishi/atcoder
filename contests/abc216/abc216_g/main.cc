#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"
#include "segment_tree.h"

void Main() {
  ints(n, m);
  using T = tuple<int, int, int>;
  V<T> v;
  rep(m) {
    ints(l, r, x);
    v.eb(r, l - 1, x);
  }
  sort(all(v));
  SegmentTree<int> t(n, [](int a, int b) { return a + b; });
  Intervals is;
  V<int> ans(n);
  for (auto [r, l, x] : v) {
    int cnt = t.Aggregate(l, r);
    if (cnt >= x) continue;
    rep(x - cnt) {
      int M = is.Max(r - 1);
      is.Insert(M, M + 1);
      t.Set(M, 1);
      ans[M] = 1;
    }
  }
  wt(ans);
}
