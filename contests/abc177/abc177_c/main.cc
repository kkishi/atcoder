#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  mint sum = accumulate(a);
  mint ans = 0;
  rep(i, n) ans += (sum - a[i]) * a[i];
  wt(ans / 2);
}
