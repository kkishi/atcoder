#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  vector seen(n + 1, vector(n + 1, false));
  vector memo(n + 1, vector(n + 1, mint(0)));
  wt(Fix([&](auto rec, int l, int r) -> mint {
    if (l == r) return 1;
    if (!seen[l][r]) {
      seen[l][r] = true;
      mint ret = rec(l + 1, r);  // l is the only child of the parent.
      rep(i, l + 1, r) {
        if (p[l] < p[i]) {
          // In addition to l, i is also a child of the parent.
          ret += rec(l + 1, i) * rec(i, r);
        }
      }
      memo[l][r] = ret;
    }
    return memo[l][r];
  })(1, n));
}
