#include <bits/stdc++.h>

#include "dual_segment_tree.h"
#include "macros.h"

using namespace std;

int main() {
  ints(n, m);

  DualSegmentTree<int> tree(m, [](int a, int b) { return a + b; });
  int total = 0;
  rep(i, n) {
    ints(l, r, s);
    total += s;
    tree.Update(l - 1, r, s);
  }
  int mini = numeric_limits<int>::max();
  rep(i, m) chmin(mini, tree.Get(i));
  wt(total - mini);
}
