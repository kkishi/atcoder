#include <bits/stdc++.h>

#include "atcoder.h"
#include "primes.h"

void Main() {
  V<bool> sieve = Sieve(200);
  wt([&] {
    ints(a, b, c, d);
    rep(A, a, b + 1) {
      bool ok = true;
      rep(B, c, d + 1) {
        if (sieve[A + B]) ok = false;
      }
      if (ok) return "Takahashi";
    }
    return "Aoki";
  }());
}
