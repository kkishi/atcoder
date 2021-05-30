#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  map<int, V<int>> av, bv;
  rep(i, n) {
    av[a[i] + i].pb(i);
    bv[b[i] + i].pb(i);
  }
  DualSegmentTree<int> pos(n, [](int a, int b) { return a + b; });
  rep(i, n) { pos.Update(i, i + 1, i); }
  rep(i, 3) dbg(i, pos.Get(i));
  int ans = 0;
  rep(i, n) {
    int x = b[i] + i;
    const auto& B = bv[x];
    auto it = lower_bound(all(B), i);
    assert(it != B.end());
    int idx = it - B.begin();
    const auto& A = av[x];
    if (sz(B) != sz(A)) {
      wt(-1);
      return;
    }
    dbg(idx);
    int j = A[idx];
    dbg(j);
    assert(b[i] + i == a[j] + j);
    int p = pos.Get(j);
    dbg(p);
    dbg(i);
    assert(p >= j);
    ans += p - i;
    pos.Update(0, j, 1);
  }
  wt(ans);
}
