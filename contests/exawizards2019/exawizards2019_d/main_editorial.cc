#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, x);
  V<int> s(n);
  cin >> s;
  sort(s, greater{});
  vector dp(n + 1, vector(x + 1, optional<mint>()));
  wt(Fix([&](auto rec, int i, int y) -> mint {
       auto& d = dp[i][y];
       if (!d) {
         if (i == n) {
           d = y;
         } else {
           mint rem = n - i;
           d = 1 / rem * rec(i + 1, y % s[i]) + (rem - 1) / rem * rec(i + 1, y);
         }
       }
       return *d;
     })(0, x) *
     mint::Fact(n));
}
