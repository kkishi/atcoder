#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  V<int> sieve(1000001, -1);
  rep(i, 2, sz(sieve)) if (sieve[i] == -1) {
    for (int j = i; j < sz(sieve); j += i) {
      sieve[j] = i;
    }
  }
  V<int> factors(1000001, -1);
  bool pc = true;
  rep(i, n) {
    int ai = a[i];
    while (ai != 1) {
      int f = sieve[ai];
      if (factors[f] != -1 && factors[f] != i) {
        pc = false;
      }
      factors[f] = i;
      ai /= f;
    }
  }
  if (pc) {
    wt("pairwise coprime");
    return;
  }
  int sgcd = a[0];
  rep(i, 1, n) sgcd = gcd(sgcd, a[i]);
  if (sgcd == 1) {
    wt("setwise coprime");
    return;
  }
  wt("not coprime");
}
