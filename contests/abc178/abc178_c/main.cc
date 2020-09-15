#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  wt(mint(10).Pow(n) - mint(9).Pow(n) - mint(9).Pow(n) + mint(8).Pow(n));
}
