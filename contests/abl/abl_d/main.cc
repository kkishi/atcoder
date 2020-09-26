#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;

  const int M = 300000;
  SegmentTree<int> tree(M + 1, [](int a, int b) { return max(a, b); });
  rep(i, n) {
    tree.Set(a[i], tree.Aggregate(max(0, a[i] - k), min(a[i] + k, M) + 1) + 1);
  }
  wt(tree.Aggregate(0, M + 1));
}
