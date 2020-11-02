#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

using Vec = Vector<int>;

void Main() {
  ints(n);
  V<Vec> v(n);
  cin >> v;
  bool ok = false;
  rep(i, n) rep(j, i + 1, n) rep(k, j + 1, n) {
    if (Cross(v[j] - v[i], v[k] - v[i]) == 0) ok = true;
  }
  wt(ok);
}
