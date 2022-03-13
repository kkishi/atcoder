#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  a.pb(0);
  sort(a);
  mint ans = 1;
  rrep(i, n) ans *= a[i + 1] - a[i] + 1;
  wt(ans);
}
