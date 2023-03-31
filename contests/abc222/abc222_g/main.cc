#include <bits/stdc++.h>

#include <atcoder/math>

#include "atcoder.h"
#include "discrete_log.h"

void Main() {
  ints(t);
  rep(t) {
    ints(k);
    if (even(k)) {
      k /= 2;
    }
    if (k == 1) {
      wt(1);
      continue;
    }
    // If k is divisible by 2 or 5, the answer is -1. We handle these cases
    // explicitly because we want to use inv_mod(10, k) below.
    if (gcd(10, k) != 1) {
      wt(-1);
      continue;
    }
    k *= 9;
    // We want DiscreteLog(10, 1, k) but want to skip 0 (note that 10^0 = 1). So
    // instead we calculate mod_log(10, 10^(-1), k).
    wt(DiscreteLog(10, atcoder::inv_mod(10, k), k) + 1);
  }
}
