#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

using Vec = Vector<double>;
using L = LineSegment<double>;

void Main() {
  rd(Vec, a, b);
  ints(n);
  V<Vec> p(n);
  cin >> p;
  int cnt = 0;
  rep(i, n) if (L{a, b}.Intersect(L{p[i], p[(i + 1) % n]}))++ cnt;
  wt(cnt / 2 + 1);
}
