#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  int n = r.Int(10, 12);
  wt(n);
  V<int> a;
  rep(n) a.pb(r.Int(1, 10));
  wt(a);
}
