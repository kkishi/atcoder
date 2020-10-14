#include <bits/stdc++.h>

#include "atcoder.h"
#include "prime.h"

void Main() {
  ints(n);
  V<bool> prime = Sieve(55555);
  int found = 0;
  for (int i = 0; found < n; ++i) {
    if (int p = i * 5 + 1; prime[p]) {
      if (found) cout << " ";
      cout << p;
      ++found;
    }
  }
  cout << endl;
}
