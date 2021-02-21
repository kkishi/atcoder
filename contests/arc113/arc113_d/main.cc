#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, k);
  if (n > m) swap(n, m);
  if (n == 1) {
    wt(mint(k).Pow(m));
    return;
  }
  mint ans = 0;
  rep(l, 1, k + 1) {
    mint x = mint(l).Pow(n);
    mint y = mint(l - 1).Pow(n);
    mint z = mint(k + 1 - l).Pow(m);
    ans += (x - y) * z;
  }
  wt(ans);
}
