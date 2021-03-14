#include <bits/stdc++.h>

#include "atcoder.h"
#include "primes.h"

void Main() {
  V<int> p = Primes(50);
  ints(n);
  V<int> x(n);
  cin >> x;
  int ans = big;
  rep(mask, 1 << sz(p)) {
    int mul = 1;
    rep(i, sz(p)) if (hasbit(mask, i)) mul *= p[i];
    bool ok = true;
    rep(i, n) if (gcd(x[i], mul) == 1) ok = false;
    if (ok) chmin(ans, mul);
  }
  wt(ans);
}
