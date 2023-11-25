#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l, r);
  V<int> a(n);
  cin >> a;
  rep(i, n) {
    chmax(a[i], l);
    chmin(a[i], r);
  }
  wt(a);
}
