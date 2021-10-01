#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  map<int, int> m;
  rep(n) {
    ints(c);
    ++m[c];
  }
  map<int, int> M;
  each(_, v, m)++ M[v];
  rep(i, 1, n + 1) {
    mint ans = 0;
    each(k, v, M) ans += v * (mint::Comb(n, i) - mint::Comb(n - k, i));
    wt(ans / mint::Comb(n, i));
  }
}
