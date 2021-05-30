#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int t = 1;
  wt(t);
  Rand r;
  rep(t) {
    int n = 100;
    V<int> p(n);
    rep(i, n) p[i] = i + 1;
    rep(i, n) swap(p[i], p[r.Int(i, n - 1)]);
    wt(n);
    wt(p);
  }
}
