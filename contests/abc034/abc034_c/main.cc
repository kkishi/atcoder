#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(w, h);
  wt(mint::Comb(w - 1 + h - 1, w - 1));
}
