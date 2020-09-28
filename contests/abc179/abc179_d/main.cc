#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"
#include "segment_tree.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  V<int> l(k), r(k);
  rep(i, k) cin >> l[i] >> r[i];
  SegmentTree<mint> tree(n, [](mint a, mint b) { return a + b; });
  tree.Set(0, 1);
  for (int i = 1; i < n; ++i) {
    mint sum = 0;
    rep(j, k) {
      int L = max(0, i - r[j]);
      int R = max(0, i - l[j] + 1);
      sum += tree.Aggregate(L, R);
    }
    tree.Set(i, sum);
  }
  wt(tree.Get(n - 1));
}
