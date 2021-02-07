#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

bool Ok(int n, int k) {
  while (n != 1) {
    if (n % k == 0) {
      n /= k;
      continue;
    } else if (n > k) {
      n %= k;
      continue;
    }
    return false;
  }
  return true;
}

void Main() {
  ints(n);
  int ans = sz(Divisors(n - 1)) - 1;
  for (int x : Divisors(n)) {
    if (x > 1 && Ok(n, x)) {
      ++ans;
    }
  }
  wt(ans);
}
