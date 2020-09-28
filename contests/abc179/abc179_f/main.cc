#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

void Main() {
  ints(n, q);
  DualSegmentTree<int> r(
      n, [](int a, int b) { return min(a, b); }, n - 2);
  DualSegmentTree<int> c(
      n, [](int a, int b) { return min(a, b); }, n - 2);
  int ans = (n - 2) * (n - 2);
  rep(q) {
    ints(a, b);
    if (b == 1) continue;
    if (a == 1) {
      int x = r.Get(b - 1);
      ans -= x;
      c.Update(1, x + 1, b - 2);
    } else {
      int x = c.Get(b - 1);
      ans -= x;
      r.Update(1, x + 1, b - 2);
    }
  }
  wt(ans);
}
