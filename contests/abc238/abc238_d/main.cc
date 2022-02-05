#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(a, s);
  int b = s - a * 2;
  return b >= 0 && ((b & a) == 0);
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}
