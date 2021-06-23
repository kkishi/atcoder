#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

mint Solve(int n, mint k) {
  if (n == 1) return k;
  if (n == 2) return k * (k - 1);
  return k * (k - 1) * (k - 2).Pow(n - 2);
}

void Main() {
  ints(n, k);
  wt(Solve(n, k));
}
