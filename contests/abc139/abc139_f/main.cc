#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

using Vec = Vector<double>;

void Main() {
  ints(n);
  V<Vec> v(n);
  cin >> v;
  double ans = 0;
  each(vi, v) each(vj, v) {
    Vec x = vi + vj;
    if (x.Norm() == 0) continue;
    Vec sum;
    each(vk, v) if ((vk / x).x > 0) sum += vk;
    chmax(ans, sum.Norm());
  }
  wt(ans);
}
