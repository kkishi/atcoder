#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n);
  if (n == 1) return false;
  auto prime = [&] {
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  };
  if (prime()) return true;
  V<int> v;
  while (n) {
    v.pb(n % 10);
    n /= 10;
  }
  return !even(v[0]) && (v[0] != 5) && (accumulate(v) % 3 != 0);
}

void Main() { wt(Solve() ? "Prime" : "Not Prime"); }
