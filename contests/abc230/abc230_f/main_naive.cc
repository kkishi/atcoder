#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  V<mint> s(n + 1);
  s[0] = 1;
  rep(i, n) {
    int sum = 0;
    rep(j, i, n) {
      sum += a[j];
      s[j + 1] += s[i];
      if (i > 0 && sum == 0) break;
    }
  }
  wt(s[n]);
}
