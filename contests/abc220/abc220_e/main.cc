#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, d);
  mint ans = 0;
  rep(dl, div_ceil(d, 2), min(n, d) + 1) {
    mint x = mint(2).Pow(n - dl) - 1;
    mint y = mint(2).Pow(max(0, dl - 1));
    int ds = d - dl;
    mint z = mint(2).Pow(max(0, ds - 1));
    mint w = x * y * z;
    if (ds == dl) {
      w *= 2;
    } else {
      w *= 4;
    }
    ans += w;
  }
  wt(ans);
}
