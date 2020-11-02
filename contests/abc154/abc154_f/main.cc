#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

mint calc(int r, int c) { return mint::Comb(r + c + 2, c + 1) - 1; }

void Main() {
  ints(r1, c1, r2, c2);
  --r1, --c1;
  wt(calc(r2, c2) - calc(r2, c1) - calc(r1, c2) + calc(r1, c1));
}
