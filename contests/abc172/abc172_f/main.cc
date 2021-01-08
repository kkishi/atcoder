#include <bits/stdc++.h>

#include "atcoder.h"

int Solve(int a, int b, int y) {
  int x = a + b;
  // Find integers A and B that satisfy the following:
  // * A + B = x
  // * A ^ B = y
  // * 0 < A <= a
  // * A is the largest integer among those that satisfy the above conditions.
  if (x < y) return -1;
  int z = x - y;
  if (z & 1) return -1;
  z >>= 1;
  if (y & z) return -1;
  int A = z, B = z;
  rrep(i, 50) {
    int bit = 1LL << i;
    if (y & bit) ((A | bit) < a ? A : B) |= bit;
  }
  assert((A + B) == x);
  assert((A ^ B) == y);
  if (0 < A && A <= a) {
    return a - A;
  }
  return -1;
}

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int c = 0;
  rep(i, 2, n) c ^= a[i];
  wt(Solve(a[0], a[1], c));
}
