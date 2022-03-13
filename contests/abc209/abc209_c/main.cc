#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  sort(c);
  mint ans = 1;
  rep(i, n) {
    int x = c[i] - i;
    if (x <= 0) {
      wt(0);
      return;
    }
    ans *= x;
  }
  wt(ans);
}
