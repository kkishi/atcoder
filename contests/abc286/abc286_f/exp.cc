#include <bits/stdc++.h>

#include "atcoder.h"
#include "primes.h"

void Main() {
  V<int> p = Primes(50);
  dbg(p);
  int n = sz(p);
  int ma = -big;
  rep(mask, 1 << n) {
    int sum = 0;
    int mul = 1;
    rep(i, n) if (hasbit(mask, i)) {
      sum += p[i];
      mul *= p[i];
    }
    if (sum <= 110) chmax(ma, mul);
  }
  wt(ma);
}
