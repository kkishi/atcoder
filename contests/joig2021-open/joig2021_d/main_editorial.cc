#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, m, d);
  V<pair<int, int>> xv(n);
  cin >> xv;
  sort(xv);
  V<int> x(n), v(n);
  rep(i, n) tie(x[i], v[i]) = xv[i];
  wt(BinarySearch<int>(-1, big, [&](int mini) {
    int last = -d;
    int cnt = 0;
    rep(i, n) {
      if (v[i] >= mini && x[i] - last >= d) {
        last = x[i];
        ++cnt;
      }
    }
    return cnt >= m;
  }));
}
