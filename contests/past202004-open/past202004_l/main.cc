#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(n, k, d);
  if (n < (k - 1) * d + 1) {
    wt(-1);
    return;
  }
  V<int> a(n);
  cin >> a;
  using P = pair<int, int>;
  SegmentTree<P> tree(
      n, [](const P& a, const P& b) { return min(a, b); }, P{big, big});
  rep(i, n) tree.Set(i, {a[i], i});
  int l = -d;
  V<int> ans;
  rep(i, k) {
    auto [ai, idx] = tree.Aggregate(l + d, n - d * (k - 1 - i));
    ans.pb(ai);
    l = idx;
  }
  wt(ans);
}
