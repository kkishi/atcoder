#include <bits/stdc++.h>

#include "atcoder.h"
#include "primes.h"

void Main() {
  ints(n);
  V<bool> s = Sieve(55555);
  int found = 0;
  for (int i = 0; found < n; ++i) {
    if (int p = i * 5 + 1; s[p]) {
      if (found) cout << " ";
      cout << p;
      ++found;
    }
  }
  cout << endl;
}
