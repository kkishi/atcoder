#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  VV<pair<int, int>> key(n);
  rep(m) {
    ints(l, r, c);
    key[l - 1].eb(r, c);
  }
  DualSegmentTree<int> t(
      n + 1, [](int a, int b) { return min(a, b); }, big);
  t.Update(0, 1, 0);
  rep(i, n) {
    int x = t.Get(i);
    for (auto [r, c] : key[i]) {
      t.Update(i + 1, r + 1, x + c);
    }
    t.Update(i + 1, i + 2, x + a[i]);
  }
  wt(accumulate(all(a), int(0)) - t.Get(n));
}
