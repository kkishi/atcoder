#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

void Main() {
  ints(N, Q);
  DualSegmentTree<int> tree(N, [](int a, int b) { return a + b; });
  rep(i, Q) {
    ints(l, r);
    tree.Update(l - 1, r, 1);
  }
  rep(i, N) cout << tree.Get(i) % 2;
  cout << endl;
}
