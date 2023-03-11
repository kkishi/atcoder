#include <bits/stdc++.h>

#include "atcoder.h"
#include "convex_hull_trick.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  // min(a[j] + (j - i)^2)
  // = min(a[j] + j^2 - 2ij) + i^2
  MinMonotoneConvexHullTrick cht;
  rep(i, n) cht.Add(-2 * i, a[i] + i * i);
  rep(i, n) wt(cht.Get(i) + i * i);
}
