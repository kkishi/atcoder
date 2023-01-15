#include <bits/stdc++.h>

#include "atcoder.h"
#include "int_sqrt.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    rep(x, 2, 10000000) {
      if (n % x == 0) {
        if (n % (x * x) == 0) {
          wt(x, n / x / x);
        } else {
          wt(IntSqrt(n / x), x);
        }
        break;
      }
    }
  }
}
