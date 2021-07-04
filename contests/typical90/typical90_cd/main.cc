#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(l, r);
  auto f = [](int x) {
    mint ret = 0;
    for (__int128_t t = 1; t <= x; t *= 10) {
      ret += mint(x) * (x + 1) / 2 - mint(t) * (t - 1) / 2;
    }
    return ret;
  };
  wt(f(r) - f(l - 1));
}
