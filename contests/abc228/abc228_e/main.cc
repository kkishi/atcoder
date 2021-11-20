#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"
#include "pow.h"

const int mod = 998244353;
using mint = ModInt<mod>;

void Main() {
  ints(n, k, m);
  if (m % mod == 0) {
    wt(0);
  } else {
    wt(mint(m).Pow(Pow(k, n, mod - 1)));
  }
}
