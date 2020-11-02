#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, a, b);
  wt(mint(2).Pow(n) - 1 - mint::CombSlow(n, a) - mint::CombSlow(n, b));
}
