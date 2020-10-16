#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int c = 1000;
  rep(i, n - 1) {
    if (a[i + 1] > a[i]) {
      int d = c / a[i];
      c -= d * a[i];
      c += d * a[i + 1];
    }
  }
  wt(c);
}
