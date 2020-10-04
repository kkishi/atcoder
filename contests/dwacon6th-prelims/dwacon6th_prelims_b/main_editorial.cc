#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> x(n);
  cin >> x;

  mint exp = 0;
  mint ans = 0;
  rep(i, n - 1) {
    exp += 1 / mint(i + 1);
    ans += (x[i + 1] - x[i]) * exp;
  }
  wt(ans * mint::Fact(n - 1));
}
