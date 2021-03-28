#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  mint ans = 0;
  rep(i, n) ans += a[i] * a[i];
  mint sum = 0;
  rrep(i, n) {
    ans += a[i] * sum;
    (sum *= 2) += a[i];
  }
  wt(ans);
}
