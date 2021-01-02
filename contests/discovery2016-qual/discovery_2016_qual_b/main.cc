#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

using P = pair<int, int>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  P inf = {big, 0};

  SegmentTree<P> t(
      n, [](P a, P b) { return min(a, b); }, inf);
  rep(i, n) t.Set(i, {a[i], i});

  P curr = t.Aggregate(0, n);
  int ans = 1;
  rep(n - 1) {
    t.Set(curr.second, inf);
    P next = t.Aggregate(0, n);
    P right = t.Aggregate(curr.second + 1, n);
    if (right.first == next.first) {
      next = right;
    }
    if (next.second < curr.second) ++ans;
    curr = next;
  }
  if (curr.second == 0) --ans;
  wt(ans);
}
