#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 100;
  Rand r;
  string rgb = "RGB";
  wt(n);
  rep(i, n * 2) { wt(r.Int(1, 1000000000), rgb[r.Int(0, 2)]); }
}
