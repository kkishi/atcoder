#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

void Main() {
  ints(n);
  V<Point> v(n);
  cin >> v;
  double ans = 0;
  each(vi, v) each(vj, v) {
    Point x = vi + vj;
    if (x.Norm() == 0) continue;
    Point sum;
    each(vk, v) if ((vk / x).x > 0) sum += vk;
    chmax(ans, sum.Norm());
  }
  wt(ans);
}
