#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"
#include "segment_tree.h"

using namespace std;

int main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  SegmentTree<int> tree(
      n, [](int a, int b) { return max(a, b); }, numeric_limits<int>::min());
  rep(i, n) tree.Set(i, a[i]);
  rep(q) {
    ints(t, x, v);
    if (t == 1) {
      tree.Set(x - 1, v);
    } else if (t == 2) {
      wt(tree.Aggregate(x - 1, v));
    } else {
      if (tree.Aggregate(x - 1, n) < v) {
        wt(n + 1);
      } else {
        wt(BinarySearch<int>(
            n, x - 2, [&](int y) { return tree.Aggregate(x - 1, y) >= v; }));
      }
    }
  }
}
