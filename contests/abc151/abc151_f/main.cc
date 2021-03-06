#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "geometry.h"

using Vec = Vector<double>;

void Main() {
  ints(N);
  V<Vec> vec(N);
  cin >> vec;
  wt(BinarySearch<double>(10000000000, 0, [&](double mid) {
    rep(i, N) rep(j, i) {
      vector<Vec> vs =
          (Circle<double>{vec[i], mid}).Intersections({vec[j], mid});
      for (const Vec& v : vs) {
        bool ok = true;
        rep(k, N) if ((vec[k] - v).Norm() > mid + 1e-9) ok = false;
        if (ok) return true;
      }
    }
    return false;
  }));
}
