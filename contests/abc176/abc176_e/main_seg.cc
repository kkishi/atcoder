#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(H, W, m);
  VV<int> hw(H);
  V<int> hm(H), wm(W);
  rep(i, m) {
    ints(h, w);
    --h, --w;
    hw[h].pb(w);
    hm[h]++;
    wm[w]++;
  }

  SegmentTree<int> tree(W, [](int a, int b) { return max(a, b); });
  rep(i, W) tree.Set(i, wm[i]);

  int ans = 0;
  rep(i, H) {
    for (int j : hw[i]) {
      tree.Set(j, wm[j] - 1);
    }
    chmax(ans, hm[i] + tree.Aggregate(0, W));
    for (int j : hw[i]) {
      tree.Set(j, wm[j]);
    }
  }
  wt(ans);
}
