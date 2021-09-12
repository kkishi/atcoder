#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "dual_segment_tree.h"

struct Event {
  int k;  // 0: add, 1: query, 2: del
  int x;
  int y;
  int d;
  int c;
  int q;
  bool operator<(const Event& e) {
    if (x != e.x) return x < e.x;
    return k < e.k;
  }
};

void Main() {
  ints(n, q);
  V<int> xm(n), ym(n), d(n), c(n);
  rep(i, n) cin >> xm[i] >> ym[i] >> d[i] >> c[i];
  V<int> a(q), b(q);
  rep(i, q) cin >> a[i] >> b[i];

  V<int> ys;
  rep(i, n) {
    ys.pb(ym[i]);
    ys.pb(ym[i] + d[i]);
  }
  rep(i, q) ys.pb(b[i]);
  Compressor cys(ys);
  DualSegmentTree<int> tree(sz(cys.coord), [](int a, int b) { return a + b; });

  V<Event> es;
  rep(i, n) {
    Event e;
    e.y = ym[i];
    e.d = d[i];
    e.c = c[i];

    e.k = 0;
    e.x = xm[i];
    es.pb(e);

    e.k = 2;
    e.x = xm[i] + d[i];
    es.pb(e);
  }
  rep(i, q) {
    Event e;
    e.k = 1;
    e.x = a[i];
    e.y = b[i];
    e.q = i;
    es.pb(e);
  }

  sort(all(es));
  V<int> ans(q);
  each(e, es) {
    if (e.k == 1) {
      int y = cys(e.y);
      ans[e.q] = tree.Get(y);
    } else {
      int l = cys(e.y);
      int h = cys(e.y + e.d);
      if (e.k == 0) {
        tree.Update(l, h + 1, e.c);
      } else {
        tree.Update(l, h + 1, -e.c);
      }
    }
  }
  each(e, ans) wt(e);
}
