#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(a, b, c, d);
  if (d < b) return false;
  a -= b;
  auto div_ceil = [](int n, int d) { return (n + d - 1) / d; };
  if (a > c) {
    a -= div_ceil(a - c, b) * b;
  }
  if (a < 0) return false;
  if (d == b) return true;
  int g = gcd(d, b);
  int lowest = a + div_ceil(c - a + 1, g) * g;
  return lowest >= b;
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}
