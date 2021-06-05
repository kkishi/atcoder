#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

void Main() {
  ints(w, n);
  DualSegmentTree<int> t(
      w + 1, [](int a, int b) { return max(a, b); }, -big);
  t.Update(0, 1, 0);
  rep(n) {
    ints(l, r, v);
    rrep(i, w) {
      int x = t.Get(i);
      if (x == -big) continue;
      int L = i + l;
      int R = min(i + r, w) + 1;
      if (L > R) continue;
      t.Update(L, R, x + v);
    }
  }
  int ans = t.Get(w);
  if (ans == -big) ans = -1;
  wt(ans);
}
