#include <bits/stdc++.h>

#include "atcoder.h"
#include "convex_hull_trick.h"

void Main() {
  ints(n, m);
  V<int> b(n), c(m);
  cin >> b >> c;
  sort(b);
  MaxConvexHullTrick cht;
  rep(i, n) cht.Add(n - i, (n - i) * b[i]);
  V<int> ans;
  rep(i, m) ans.eb(cht.Get(c[i]));
  wt(ans);
}
