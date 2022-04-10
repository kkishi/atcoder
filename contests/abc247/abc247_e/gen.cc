#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 100;
  Rand r;
  int x = r.Int(1, 10);
  int y = r.Int(1, 10);
  if (y > x) swap(x, y);
  wt(n, x, y);
  V<int> a(n);
  rep(i, n) a[i] = r.Int(1, 10);
  wt(a);
}
