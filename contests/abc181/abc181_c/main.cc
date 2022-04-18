#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

void Main() {
  ints(n);
  V<Point> p(n);
  cin >> p;
  bool ok = false;
  rep(i, n) rep(j, i) rep(k, j) {
    if (Intersect(Line{p[i], p[j]}, p[k])) ok = true;
  }
  wt(ok);
}
