#include <bits/stdc++.h>

#include "macros.h"
#include "segment_tree.h"

using namespace std;

struct Q {
  int l, r, i, v;
};

int main() {
  rd(int, n, q);
  V<int> c(n);
  cin >> c;
  V<Q> qs;
  rep(i, q) {
    rd(int, l, r);
    --l, --r;
    qs.push_back({l, r, i, 0});
  }
  sort(all(qs), [](const Q& a, const Q& b) { return a.r < b.r; });
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
