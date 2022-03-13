#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "dual_segment_tree.h"

void Main() {
  ints(n, q);
  V<pair<int, int>> lr(n - 1);
  cin >> lr;
  VV<pair<int, int>> qs(n);
  rep(i, q) {
    ints(a, b);
    qs[b - 1].eb(a, i);
  }

  V<int> v;
  v.pb(0);
  each(l, r, lr) {
    v.pb(l);
    v.pb(r + 1);
  }
  each(qi, qs) each(a, _, qi) v.pb(a);
  Compressor c(v);

  V<int> ans(q);
  rep(2) {
    DualSegmentTree<int> t(sz(c.coord), [](int a, int b) { return max(a, b); });
    rep(i, n - 1) {
      auto [l, r] = lr[i];
      t.Update(c(0), c(l), i + 1);
      t.Update(c(r + 1), sz(c.coord), i + 1);
      each(a, j, qs[i + 1]) ans[j] += i + 1 - t.Get(c(a));
    }
    reverse(lr);
    reverse(qs);
  }
  rep(i, q) wt(ans[i] + 1);
}
