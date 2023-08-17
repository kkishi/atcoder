#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "atcoder.h"

void Main() {
  ints(n, m);
  vector a(n, vector(m, int(0)));
  cin >> a;
  V<tuple<int, int, int>> v;
  rep(i, n) rep(j, m) v.eb(a[i][j], i, j);
  sort(v);
  AddSegmentTree<int> t(n);
  int ans = 0;
  for (auto [_, i, __] : v) {
    int x = t.Get(i);
    ans += t.Aggregate(i + 1, n) + (x + 1) * (n - 1 - i);
    t.Set(i, x + 1);
  }
  wt(ans);
}
