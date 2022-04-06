#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "atcoder.h"

void Main() {
  ints(n);
  AddSegmentTree<int> t(n);
  rep(i, n) {
    ints(x, y);
    int cnt = t.Aggregate(i - x, i);
    if (cnt >= y) t.Set(i, 1);
  }
  wt(t.Aggregate(0, n));
}
