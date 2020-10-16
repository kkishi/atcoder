#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  sort(all(c));

  mint ans = 0;
  mint sum = 0;
  rep(i, n) {
    ans = ans * 2 + mint(c[i]) * mint(2).Pow(i) + sum;
    sum = sum * 2 + mint(c[i]) * mint(2).Pow(i);
  }
  wt(ans * mint(2).Pow(n));
}
