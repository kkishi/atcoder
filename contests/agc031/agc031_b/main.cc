#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  map<int, mint> c;
  mint dp = 1;
  int PC = -1;
  rep(n) {
    ints(C);
    if (C != PC) {
      dp += c[C];
      c[C] = dp;
    }
    PC = C;
  }
  wt(dp);
}
