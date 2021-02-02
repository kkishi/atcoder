#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  vector b(k + 1, vector(n, mint(1)));
  rep(i, k) rep(j, n) b[i + 1][j] = b[i][j] * a[j];
  V<mint> s(k + 1);
  rep(i, k + 1) s[i] = accumulate(all(b[i]), mint(0));
  rep(i, 1, k + 1) {
    mint sum = 0;
    rep(j, i + 1) sum += mint::Comb(i, j) * (s[i - j] * s[j] - s[i]);
    wt(sum / 2);
#ifdef DEBUG
    mint slow = 0;
    rep(l, n) {
      rep(j, i + 1) slow += mint::Comb(i, j) * b[i - j][l] * (s[j] - b[j][l]);
    }
    assert(sum == slow);
#endif
  }
}
