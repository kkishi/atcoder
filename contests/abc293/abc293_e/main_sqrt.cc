#include <bits/stdc++.h>

#include <atcoder/modint>

#include "atcoder.h"
#include "int_sqrt.h"

using mint = atcoder::modint;

void Main() {
  ints(a, x, m);
  mint::set_mod(m);
  int sq = IntSqrt(x);
  mint s = 0, p = 1;
  rep(sq) {
    s += p;
    p *= a;
  }
  mint ans = 0;
  rep(sq) ans = ans * p + s;
  rep(x - sq * sq) ans = ans * a + 1;
  wt(ans.val());
}
