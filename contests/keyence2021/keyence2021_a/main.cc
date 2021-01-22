#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  int am = -big;
  int c = -big;
  rep(i, n) {
    chmax(am, a[i]);
    chmax(c, am * b[i]);
    wt(c);
  }
}
