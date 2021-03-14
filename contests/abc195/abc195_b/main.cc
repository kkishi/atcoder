#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, w);
  w *= 1000;
  V<int> ok;
  rep(i, 1, 1000001) {
    if (i * a <= w && w <= i * b) ok.pb(i);
  }
  if (ok.empty()) {
    wt("UNSATISFIABLE");
  } else {
    wt(ok[0], ok.back());
  }
}
