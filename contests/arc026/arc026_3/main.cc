#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

void Main() {
  ints(n, L);
  V<tuple<int, int, int>> v;
  rep(n) {
    ints(l, r, c);
    v.eb(l, r, c);
  }
  sort(all(v));
  DualSegmentTree<int> t(
      L + 1, [](int a, int b) { return min(a, b); },
      big);
  t.Update(0, 1, 0);
  for (auto [l, r, c] : v) {
    t.Update(l, r + 1, t.Get(l) + c);
  }
  wt(t.Get(L));
}
