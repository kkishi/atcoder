#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m, k);
  mint ans = 0;
  rep(2) {
    mint x = 0;
    rep(i, 1, m) x += i * (m - i);
    ans += mint::Comb(k, 2) * x * 2 * mint(n).Pow(2) *
           mint::Comb(n * m - 2, k - 2) * mint::Fact(k - 2) / mint::Fact(k);
    swap(n, m);
  }
  wt(ans);
}
