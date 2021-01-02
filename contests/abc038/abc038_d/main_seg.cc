#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(n);
  V<pair<int, int>> wh(n);
  cin >> wh;
  rep(i, n) wh[i].second *= -1;
  sort(all(wh));
  SegmentTree<int> tree(
      100001, [](int a, int b) { return max(a, b); },
      -big);
  for (auto [w, h] : wh) {
    h *= -1;
    tree.Set(h, max(0, tree.Aggregate(0, h)) + 1);
  }
  wt(tree.Aggregate(0, 100001));
}
