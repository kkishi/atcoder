#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 100;
  int m = 100;
  wt(n, m);
  V<int> a(n);
  Rand r;
  rep(i, n) a[i] = r.Int(-100, 100);
  wt(a);
}
