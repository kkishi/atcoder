#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, p);
  wt(mint(p - 1) * mint(p - 2).Pow(n - 1));
}
