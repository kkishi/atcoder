#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, p, q, r, s);
  V<int> a(n);
  cin >> a;
  V<int> b = a;
  rep(i, q - p + 1) {
    b[i + p - 1] = a[i + r - 1];
    b[i + r - 1] = a[i + p - 1];
  }
  wt(b);
}
