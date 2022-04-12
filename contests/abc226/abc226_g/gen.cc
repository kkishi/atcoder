#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int t = 1;
  wt(t);
  Rand r;
  V<int> a(5), b(5);
  rep(i, 5) a[i] = r.Int(5, 10);
  rep(i, 5) b[i] = r.Int(5, 10);
  if (accumulate(a) > accumulate(b)) swap(a, b);
  if (a[4] > b[4]) swap(a[4], b[4]);
  wt(a, b);
}
