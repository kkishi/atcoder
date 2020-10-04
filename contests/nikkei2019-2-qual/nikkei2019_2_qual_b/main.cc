#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> d(n);
  cin >> d;

  rep(i, n) if ((i == 0) != (d[i] == 0)) {
    wt(0);
    return;
  }

  V<int> cnt(n);
  rep(i, n)++ cnt[d[i]];

  mint ans = 1;
  rep(i, 1, n) ans *= mint(cnt[i - 1]).Pow(cnt[i]);
  wt(ans);
}
