#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 20;
  wt(n);
  V<int> c(n);
  Rand r;
  rep(i, n) c[i] = r.Int(1, n);
  wt(c);
  rep(i, n - 1) wt(i + 2, r.Int(1, i + 1));
}
