#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(a, b, c);
  wt(mint(a) * (a + 1) / 2 * b * (b + 1) / 2 * c * (c + 1) / 2);
}
