#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

void Main() {
  rd(int, n, m);
  DualSegmentTree<int> tree(n, [](int a, int b) { return a + b; });
  rep(i, m) {
    rd(int, l, r);
    tree.Update(l - 1, r, 1);
  }
  int ans = 0;
  rep(i, n) if (tree.Get(i) == m)++ ans;
  wt(ans);
}
