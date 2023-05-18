#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> b;
  rep(i, n - 1) {
    b.eb(a[i]);
    int sign = a[i + 1] > a[i] ? 1 : -1;
    while (true) {
      a[i] += sign;
      if (a[i] == a[i + 1]) break;
      b.eb(a[i]);
    }
  }
  b.eb(a.back());
  wt(b);
}
