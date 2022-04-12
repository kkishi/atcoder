#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  mint ans = 0;
  Fix([&](auto rec, mint v, int l, int len, int sum) {
    if (sum == n) {
      ans += v * mint(l).Pow(k);
      return;
    }
    if (len > n - sum) return;
    rec(v, l, len + 1, sum);
    for (int cnt = 1; cnt * len + sum <= n; ++cnt) {
      rec(v / (mint(len).Pow(cnt) * mint::Fact(cnt)), lcm(l, len), len + 1,
          cnt * len + sum);
    }
  })(mint::Fact(n), 1, 1, 0);
  wt(ans);
}
