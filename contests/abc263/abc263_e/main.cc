#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n - 1);
  cin >> a;
  AddSegmentTree<mint> t(n);
  rrep(i, n - 1) {
    t.Set(i, (a[i] + 1 + t.Aggregate(i + 1, i + 1 + a[i])) / a[i]);
  }
  wt(t.Get(0));
}
