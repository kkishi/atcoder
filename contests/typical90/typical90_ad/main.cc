#include <bits/stdc++.h>

#include "atcoder.h"

V<int> sieve(10000001);

void Main() {
  rep(i, 2, sz(sieve)) {
    if (sieve[i] == 0) {
      for (int j = i; j < sz(sieve); j += i) {
        ++sieve[j];
      }
    }
  }
  ints(n, k);
  int ans = 0;
  rep(i, 2, n + 1) if (sieve[i] >= k)++ ans;
  wt(ans);
}
