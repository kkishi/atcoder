#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

// This solution is TLE.
void Main() {
  ints(n, a, b, c);
  vector memo(n + 1, vector(n + 1, optional<mint>()));
  wt(Fix([&](auto rec, int na, int nb) -> mint {
    optional<mint>& m = memo[na][nb];
    if (!m) {
      if (na == 0 || nb == 0) {
        m = 0;
      } else {
        m = (100 + a * rec(na - 1, nb) + b * rec(na, nb - 1)) / (100 - c);
      }
    }
    return *m;
  })(n, n));
}
