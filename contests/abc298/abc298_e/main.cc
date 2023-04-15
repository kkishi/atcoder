#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, a, b, p, q);
  vector memo(n + 1, vector(n + 1, vector(2, mint(0))));
  vector seen(n + 1, vector(n + 1, vector(2, int(0))));
  wt(Fix([&](auto rec, int x, int y, int st) -> mint {
    if (x == n) return 1;
    if (y == n) return 0;
    mint& m = memo[x][y][st];
    int& s = seen[x][y][st];
    if (!s) {
      s = 1;
      int z = st == 0 ? p : q;
      m = 0;
      rep(i, 1, z + 1) {
        int nx = min(n, x + i);
        m += 1 - rec(y, nx, 1 - st);
      }
      m /= z;
    }
    return m;
  })(a, b, 0));
}
