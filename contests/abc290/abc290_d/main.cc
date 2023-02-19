#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n, d, k);
    --k;
    // n = 10, d = 4
    int g = gcd(d, n);  // 2
    int ng = n / g;     // 5
    int offset = k / ng;
    int rem = k % ng;
    wt(offset + (rem * d) % n);
  }
}
