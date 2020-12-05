#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  int sum = accumulate(all(a), 0LL);
  wt(mint::CombSlow(m + n, sum + n));
}
