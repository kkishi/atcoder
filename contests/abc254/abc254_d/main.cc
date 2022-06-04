#include <bits/stdc++.h>

#include "atcoder.h"
#include "int_sqrt.h"
#include "sieve.h"

void Main() {
  ints(n);
  Sieve s(200000);
  int ans = 0;
  rep(i, 1, n + 1) {
    int I = 1;
    each(k, v, s.Factors(i)) {
      if (!even(v)) I *= k;
    }
    ans += IntSqrt(n / I);
  }
  wt(ans);
}
