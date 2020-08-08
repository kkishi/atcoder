#include <bits/stdc++.h>

#include "dual_segment_tree.h"
#include "macros.h"

using namespace std;

int main() {
  rd(int, N, Q);
  DualSegmentTree<int> tree(N, [](int a, int b) { return a + b; });
  rep(i, Q) {
    rd(int, l, r);
    tree.Update(l - 1, r, 1);
  }
  rep(i, N) cout << tree.Get(i) % 2;
  cout << endl;
}
