#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  map<int, int> cnt;
  each(e, a)++ cnt[e];
  VV<int> pos(m + 1);
  rep(i, n) pos[a[i]].eb(i);

  using P = pair<int, int>;
  SegmentTree<P> t(n, [](P a, P b) { return min(a, b); }, {big, 0});
  rep(i, n) t.Set(i, P{a[i], i});

  V<int> b;
  V<int> in_b(m + 1);
  int l = 0;
  int r = 0;
  rep(i, m) {
    while (r < n) {
      int x = a[r];
      if (!in_b[x] && cnt[x] == 1) break;
      --cnt[x];
      ++r;
    }
    auto [x, idx] = t.Aggregate(l, min(r + 1, n));
    b.eb(x);
    in_b[x] = true;
    l = idx + 1;
    each(i, pos[x]) t.Set(i, P{big, 0});
  }
  wt(b);
}
