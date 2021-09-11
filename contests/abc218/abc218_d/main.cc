#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  map<pair<int, int>, int> m;
  rep(i, n) {
    cin >> x[i] >> y[i];
    ++m[{x[i], y[i]}];
  }
  int ans = 0;
  rep(i, n) rep(j, i + 1, n) {
    int minx = min(x[i], x[j]);
    int maxx = max(x[i], x[j]);
    int miny = min(y[i], y[j]);
    int maxy = max(y[i], y[j]);
    if (minx == maxx || miny == maxy) {
      continue;
    }
    if (m[{minx, miny}] && m[{minx, maxy}] && m[{maxx, miny}] &&
        m[{maxx, maxy}]) {
      ++ans;
    }
  }
  wt(ans / 2);
}
