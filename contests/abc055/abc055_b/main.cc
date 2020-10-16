#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  mint ans = 1;
  rep(i, n) ans *= i + 1;
  wt(ans);
}
