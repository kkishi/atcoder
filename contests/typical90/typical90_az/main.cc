#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  vector v(n, vector(6, int(0)));
  cin >> v;
  mint ans = 1;
  rep(i, n) ans *= accumulate(all(v[i]), mint(0));
  wt(ans);
}
