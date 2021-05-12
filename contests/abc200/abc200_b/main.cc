#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  rep(k) {
    if (n % 200 == 0) {
      n /= 200;
    } else {
      n *= 1000;
      n += 200;
    }
  }
  wt(n);
}
