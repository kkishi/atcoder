#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "atcoder.h"

void Main() {
  ints(n, q, x);
  V<int> p(n);
  cin >> p;
  int xi;
  rep(i, n) {
    if (p[i] == x) xi = i;
    p[i] = p[i] >= x;
  }
  update_sum::segtree t(p);
  rep(q) {
    ints(c, l, r);
    --l;
    int x = t.prod(l, r).val;
    bool update_xi = (l <= xi && xi < r);
    t.apply(l, r, 0);
    if (c == 1) {
      t.apply(r - x, r, 1);
      if (update_xi) xi = r - x;
    } else {
      t.apply(l, l + x, 1);
      if (update_xi) xi = l + x - 1;
    }
  }
  wt(xi + 1);
}
