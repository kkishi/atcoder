#include <bits/stdc++.h>

#include "pclib/dual_segment_tree.h"
#include "pclib/macros.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  rd(int, n, m);

  DualSegmentTree<int> tree(m, [](int a, int b) { return a + b; });
  int total = 0;
  rep(i, n) {
    rd(int, l, r, s);
    total += s;
    tree.Update(l - 1, r, s);
  }
  int mini = numeric_limits<int>::max();
  rep(i, m) mini = min(mini, tree.Get(i));
  wt(total - mini);
}
