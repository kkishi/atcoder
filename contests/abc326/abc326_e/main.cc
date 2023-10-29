#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  mint sum_a = 0;
  mint sum_dp = 0;
  rrep(i, n) {
    sum_dp += (sum_a + sum_dp) / n;
    sum_a += a[i];
  }
  wt((sum_a + sum_dp) / n);
}
