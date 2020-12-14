#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(n, q);
  SegmentTree<int> t(n, [](int a, int b) { return a ^ b; });
  rep(i, n) {
    ints(a);
    t.Set(i, a);
  }
  rep(q) {
    ints(T, x, y);
    if (T == 1) {
      t.Set(x - 1, t.Get(x - 1) ^ y);
    } else {
      wt(t.Aggregate(x - 1, y));
    }
  }
}
