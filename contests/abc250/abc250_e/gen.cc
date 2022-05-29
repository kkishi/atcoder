#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 5;
  wt(n);
  Rand r;
  rep(2) {
    V<int> v;
    rep(n) v.pb(r.Int(1, 5));
    wt(v);
  }
  int q = n * n;
  wt(q);
  rep(x, n) rep(y, n) wt(x + 1, y + 1);
}
