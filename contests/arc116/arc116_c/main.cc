#include <bits/stdc++.h>

#include "atcoder.h"
#include "factors.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  mint ans = 0;
  for (int x = 1; x <= m; ++x) {
    map<int, int> fs = Factors(x);
    mint p = 1;
    each(_, v, fs) p *= mint::Comb(n - 1 + v, v);
    ans += p;
  }
  wt(ans);
}
