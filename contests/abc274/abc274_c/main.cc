#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> v(n * 2 + 1);
  wt(0);
  rep(i, n) {
    int x = v[a[i] - 1] + 1;
    rep(2) wt(x);
    v[i * 2 + 1] = x;
    v[i * 2 + 2] = x;
  }
}
