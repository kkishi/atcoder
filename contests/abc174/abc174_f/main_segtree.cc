#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

struct Q {
  int l, r, i, v;
};

void Main() {
  ints(n, q);
  V<int> c(n);
  cin >> c;
  V<Q> qs;
  rep(i, q) {
    ints(l, r);
    --l, --r;
    qs.pb({l, r, i, 0});
  }
  sort(qs, [](const Q& a, const Q& b) { return a.r < b.r; });
  V<int> seen(n, -1);
  SegmentTree<int> tree(n, [](int a, int b) { return a + b; });
  auto qit = qs.begin();
  V<int> ans(q);
  rep(i, n) {
    int& s = seen[c[i] - 1];
    if (s != -1) {
      tree.Set(s, 0);
    }
    s = i;
    tree.Set(i, 1);
    while (qit != qs.end() && qit->r == i) {
      ans[qit->i] = tree.Aggregate(qit->l, qit->r + 1);
      ++qit;
    }
  }
  rep(i, q) wt(ans[i]);
}
