#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "primes.h"

int cube(int x) { return x * x * x; }
int square(int x) { return x * x; }

void Main() {
  V<int> primes = Primes(1010000);
  ints(n);
  int ans = 0;
  int mbi = 0;
  each(a, primes) {
    int x = n / (a * a);
    if (x <= a) break;
    while (primes[mbi] <= a) ++mbi;
    for (int bi = mbi; cube(primes[bi]) < n; ++bi) {
      int b = primes[bi];
      int y = x / b;
      int c = primes[bi + 1];
      if (square(c) <= y) {
        int ci = BinarySearch<int>(bi + 1, sz(primes), [&](int ci) {
          return square(primes[ci]) <= y;
        });
        ans += ci - bi;
      }
    }
  }
  wt(ans);
}
