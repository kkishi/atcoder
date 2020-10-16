#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  if (abs(n - m) > 1) {
    wt(0);
  } else {
    mint x = mint::Fact(n) * mint::Fact(m);
    if (n == m) {
      x *= 2;
    }
    wt(x);
  }
}
