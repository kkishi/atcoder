#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  int q = n / m;
  int r = n % m;
  map<int, int> M;
  M[q + 1] = r;
  M[q] = m - r;
  rep(N, 1, n + 1) {
    mint x = 0;
    rep(i, N) {
      mint y = 1;
      each(k, v, M) y *= mint::Perm(N - i, k).Pow(v);
      x += (even(i) ? 1 : -1) * mint::Comb(N, i) * y;
    }
    wt(x / mint::Fact(N));
  }
}
