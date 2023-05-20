#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 20;
  wt(n);
  V<int> a;
  Rand r;
  rep(n) a.eb(r.Int(1, 4));
  wt(a);
}
