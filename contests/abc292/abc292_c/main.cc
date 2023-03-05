#include <bits/stdc++.h>

#include "atcoder.h"
#include "sieve.h"

void Main() {
  ints(n);
  Sieve sieve(n);
  int ans = 0;
  rep(a, 1, n) {
    for (int b = 1; a * b < n; ++b) {
      int p = 1;
      each(_, e, sieve.Factors(n - a * b)) p *= e + 1;
      ans += p;
    }
  }
  wt(ans);
}
