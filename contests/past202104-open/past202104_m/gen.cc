#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 10;
  wt(n);
  Rand r;
  rep(i, n) wt(r.Int(1, 10));
  int q = 10;
  wt(q);
  rep(q) {
    int l = r.Int(1, n);
    wt(l, r.Int(l, n), r.Int(1, 10));
  }
}
