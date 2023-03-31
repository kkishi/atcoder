#include <bits/stdc++.h>

#include "atcoder.h"
#include "primes.h"
#include "rand.h"

void Main() {
  int t = 1;
  wt(t);
  Rand r;
  V<int> primes = Primes(30);
  int p = primes[r.Int(0, sz(primes) - 1)];
  V<int> v = {p};
  rep(4) v.eb(r.Int(0, p - 1));
  wt(v);
}
