#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  int h = 10, w = 10, s = r.Int(1, h * w);
  wt(h, w, s);
  rep(i, h) {
    rep(j, h) { wt(r.Int(10, 20)); }
  }
}
