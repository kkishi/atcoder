#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(n);
  V<int> h(n), a(n);
  cin >> h >> a;
  SegmentTree<int> tree(n, [](int a, int b) { return max(a, b); });
  rep(i, n) tree.Set(h[i] - 1, tree.Aggregate(0, h[i]) + a[i]);
  wt(tree.Aggregate(0, n));
}
