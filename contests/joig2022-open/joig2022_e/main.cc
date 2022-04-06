#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(n, m);
  SegmentTree<int> t(
      m, [](int a, int b) { return max(a, b); }, 0);
  rep(n) {
    ints(a, v);
    --a;
    int ma = max(t.Aggregate(0, a), t.Aggregate(a + 1, m));
    t.Set(a, max(t.Get(a), ma + v));
  }
  wt(t.Aggregate(0, m));
}
