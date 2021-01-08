#include <bits/stdc++.h>

#include "atcoder.h"
#include "gcd.h"

int Solve() {
  ints(n, s, k);
  auto [g, x, y] = ExtGcd(n, k);
  int t = n - s;
  if (t % g != 0) return -1;
  n /= g;
  t /= g;
  return t * (y + n) % n;
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}
