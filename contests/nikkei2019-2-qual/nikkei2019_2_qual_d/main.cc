#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> v;
  rep(m) {
    ints(l, r, c);
    v.emplace_back(l, r, c);
  }
  sort(all(v));
  const int inf = numeric_limits<int>::max() / 10;
  DualSegmentTree<int> tree(
      n, [](int a, int b) { return min(a, b); }, inf);
  tree.Update(0, 1, 0);
  for (auto [l, r, c] : v) {
    tree.Update(l, r, tree.Get(l - 1) + c);
  }
  int ans = tree.Get(n - 1);
  wt(ans == inf ? -1 : ans);
}
