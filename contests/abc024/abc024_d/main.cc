#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(A, B, C);
  mint a = A, b = B, c = C;
  mint x = a * c + a * b, y = b * c;
  mint n = (2 * y - x) / (x - y);
  mint k = a / c * (n + 1) - 1;
  wt(k, n - k);
}
