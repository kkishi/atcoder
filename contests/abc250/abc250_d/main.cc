#include <bits/stdc++.h>

#include "atcoder.h"
#include "count.h"
#include "pow.h"
#include "primes.h"

void Main() {
  V<int> p = Primes(1000000);
  ints(n);
  int ans = 0;
  rep(i, 1, sz(p)) {
    int p3 = Pow(p[i], 3);
    int x = min(n / p3, p[i] - 1);
    ans += CountLE(p, x);
  }
  wt(ans);
}
