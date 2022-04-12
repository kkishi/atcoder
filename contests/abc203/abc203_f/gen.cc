#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 10, k = 3;
  wt(n, k);
  Rand r;
  V<int> a;
  rep(n) a.eb(r.Int(1, 10));
  wt(a);
}
