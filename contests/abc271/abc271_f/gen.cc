#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 20;
  wt(n);
  vector a(n, vector(n, int(0)));
  Rand r;
  rep(i, n) rep(j, n) a[i][j] = r.Int(0, (1 << 30) - 1);
  each(e, a) wt(e);
}
