#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  mint ans = 1;
  for (auto [_, v] : Factors(m)) {
    ans *= mint::Comb(n - 1 + v, n - 1);
  }
  wt(ans);
}
