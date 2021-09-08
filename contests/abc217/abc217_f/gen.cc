#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  int n = 4;
  int m = n * n * 3;
  wt(n, m);
  rep(m) { wt(r.Int(1, n * 2), r.Int(1, n * 2)); }
}
