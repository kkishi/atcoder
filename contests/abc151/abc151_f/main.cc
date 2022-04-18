#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "geometry.h"

void Main() {
  ints(n);
  V<Point> p(n);
  cin >> p;
  wt(BinarySearch<Float>(10000000000, 0, [&](Float mid) {
    rep(i, n) rep(j, i) {
      vector<Point> vs = (Circle{p[i], mid}).Intersections({p[j], mid});
      for (const Point& v : vs) {
        bool ok = true;
        rep(k, n) if (Sign((p[k] - v).Norm() - mid) > 0) ok = false;
        if (ok) return true;
      }
    }
    return false;
  }));
}
