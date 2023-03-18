#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 10, q = 10;
  wt(n, q);
  V<int> a;
  Rand r;
  rep(n) a.eb(r.Int(0, 2));
  wt(a);
  rep(q) {
    int t = r.Int(1, 2);
    int L = r.Int(1, n), R = r.Int(1, n);
    if (L > R) swap(L, R);
    if (t == 1) {
      wt(t, L, R);
    } else {
      V<int> p;
      rep(3) p.eb(r.Int(0, 2));
      wt(t, L, R, p);
    }
  }
}
