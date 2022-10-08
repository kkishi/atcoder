#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  V<Intervals> v(m + 1);
  rep(i, n) {
    int d = i + 1;
    int j = max(div_ceil(-a[i], d), 0);
    while (j <= m) {
      int y = a[i] + d * j;
      if (y >= n) break;
      v[j].Erase(y, y + 1);
      v[j].Insert(y, y + 1);
      ++j;
    }
  }
  rep(i, m) wt(v[i + 1].Mex(0));
}
