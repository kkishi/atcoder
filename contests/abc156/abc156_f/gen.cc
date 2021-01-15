#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  int k = 10;
  wt(k, 1);
  rep(i, k) wt(r.Int(0, 10));
  wt(100, r.Int(0, 10), r.Int(3, 10));
}
