#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 12, q = 1;
  wt(n, q);
  V<int> a{0};
  Random r;
  rep(n - 1) {
    int x = a.back() + r.Int(1, 10);
    a.pb(x);
  }
  rep(i, n) wt(a[i]);
  rep(q) wt(r.Int(1, n * 10));
}
