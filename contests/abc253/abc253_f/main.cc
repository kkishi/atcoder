#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

void Main() {
  ints(n, m, q);
  swap(n, m);
  V<tuple<int, int, int, int>> qs;
  VV<tuple<int, int, int>> L(q);
  V<pair<int, int>> two(m);
  rep(qi, q) {
    ints(k);
    if (k == 1) {
      ints(l, r, x);
      --l;
      qs.eb(1, l, r, x);
    } else if (k == 2) {
      ints(i, x);
      --i;
      two[i] = {qi, x};
      qs.eb(2, i, x, 0);
    } else {
      ints(i, j);
      --i, --j;
      auto [qj, x] = two[i];
      L[qj].eb(x, j, qi);
      qs.eb(3, i, j, 0);
    }
  }
  DualSegmentTree<int> tree(n, [](int a, int b) { return a + b; });
  V<int> ans(q);
  rep(i, q) {
    for (auto [x, j, qi] : L[i]) {
      ans[qi] = x - tree.Get(j);
    }
    auto e = qs[i];
    int k = get<0>(e);
    if (k == 1) {
      auto [_, l, r, x] = e;
      tree.Update(l, r, x);
    } else if (k == 3) {
      int j = get<2>(e);
      ans[i] += tree.Get(j);
      wt(ans[i]);
    }
  }
}
