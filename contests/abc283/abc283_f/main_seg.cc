#include <bits/stdc++.h>

#include "atcoder.h"
#include "max_segment_tree.h"

void Main() {
  ints(n);
  using E = tuple<int, int, int>;  // x, y, index
  V<E> v;
  rep(i, n) {
    ints(p);
    v.eb(i, p - 1, i);
  }
  auto solve = [&](const V<E>& v) {
    MaxSegmentTree<int> t(n);
    V<int> ret(n);
    for (auto [x, y, i] : v) {
      int z = t.Aggregate(0, y);
      if (z == numeric_limits<int>::min()) {
        ret[i] = big;
      } else {
        ret[i] = x + y - t.Aggregate(0, y);
      }
      t.Set(y, x + y);
    }
    return ret;
  };
  V<int> ans(n, big);
  rep(4) {
    // Rotate 90 degree.
    rep(i, n) {
      auto [x, y, _] = v[i];
      v[i] = {y, n - 1 - x, _};
    }
    sort(v);
    V<int> res = solve(v);
    rep(i, n) chmin(ans[i], res[i]);
  }
  wt(ans);
}
