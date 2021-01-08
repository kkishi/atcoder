#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 8, k = 2;
  wt(n, k);
  V<int> p(n);
  iota(all(p), 1);
  Random r;
  rep(i, n - 1) swap(p[i], p[r.Int(i, n - 1)]);
  rep(i, n) wt(p[i]);
}
