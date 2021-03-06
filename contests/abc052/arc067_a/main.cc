#include <bits/stdc++.h>

#include "atcoder.h"
#include "factors.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  map<int, int> fs;
  rep(i, 2, n + 1) for (auto [k, v] : Factors(i)) fs[k] += v;
  mint ans = 1;
  for (auto [_, v] : fs) ans *= v + 1;
  wt(ans);
}
