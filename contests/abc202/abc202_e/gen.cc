#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 4;
  wt(n);
  Rand r;
  rep(i, n - 1) wt(r.Int(1, 1 + i));
  int q = n * n;
  wt(q);
  rep(i, n) rep(j, n) { wt(i + 1, j); }
}
