#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> b(30);
  rep(i, 30) rep(j, n) if (hasbit(a[j], i))++ b[i];
  int D = 0;
  rep(i, n) {
    int d = 0;
    rep(j, 30) if (hasbit(a[i], j)) d += (1 << j) * (n - b[j] * 2);
    chmax(D, d);
  }
  wt(accumulate(a) + D);
}
