#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(n, p, q, r);
    V<int> a(n);
    cin >> a;
    int x = 0, y = 0, z = 0, w = 0;
    int xy = 0, xz = 0, xw = 0;
    while (x < n) {
      while (xy < p && y < n) xy += a[y++];
      while (xz < p + q && z < n) xz += a[z++];
      while (xw < p + q + r && w < n) xw += a[w++];
      if (xy == p && xz == p + q && xw == p + q + r) return true;
      xy -= a[x];
      xz -= a[x];
      xw -= a[x];
      ++x;
    }
    return false;
  }());
}
