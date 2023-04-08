#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "max_segment_tree.h"

void Main() {
  ints(n);
  int inf = 1000000001;
  V<int> v = {0, inf};
  using P = pair<int, int>;
  V<P> p;
  rep(n) {
    ints(l, r);
    v.eb(l);
    v.eb(r);
    p.eb(l, r);
  }
  Compressor cmp(v);
  int cn = sz(cmp.coord);
  MaxSegmentTree<int> tree1(cn), tree2(cn);

  int ans = 0;
  each(l, r, p) {
    int cl = cmp(l);
    int cr = cmp(r);
    int x = r - l + 1;
    chmax(x, x + tree1.Aggregate(0, cl));
    chmax(x, r + tree2.Aggregate(cl, cr));
    chmax(ans, x);
    tree1.Set(cr, x);
    tree2.Set(cr, x - r);
  }
  wt(ans);
}
