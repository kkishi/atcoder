#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(a, b, c, d, e, f);
  wt(mint(a) * b * c - mint(d) * e * f);
}
