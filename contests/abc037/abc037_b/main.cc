#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  rep(q) {
    ints(l, r, t);
    rep(i, l - 1, r) a[i] = t;
  }
  rep(i, n) wt(a[i]);
}
