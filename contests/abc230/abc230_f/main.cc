#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  map<int, int> seen;
  seen[0] = n;
  int sum = 0;
  V<int> R(n, n);
  rrep(i, n) {
    sum += a[i];
    if (seen.count(sum)) {
      R[i] = seen[sum];
    }
    seen[sum] = i;
  }
  DualSegmentTree<mint> t(n + 1, [](mint a, mint b) { return a + b; });
  t.Update(0, 1, 1);
  rep(i, n) {
    mint x = t.Get(i);
    int r = R[i];
    if (i == 0) r = n;
    t.Update(i + 1, r + 1, x);
  }
  wt(t.Get(n));
}
