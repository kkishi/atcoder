#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(a, b, c, d);
  rep(10000) {
    a -= b;
    if (a < 0) return false;
    if (a <= c) a += d;
  }
  return true;
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}
