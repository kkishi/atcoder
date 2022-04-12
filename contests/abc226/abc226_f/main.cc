#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  V<pair<int, int>> v;
  mint ans = 0;
  Fix([&](auto rec, int sum) {
    if (sum == n) {
      mint cnt = mint::Fact(n);
      each(a, b, v) {
        cnt /= mint::Fact(b);
        cnt /= mint(a).Pow(b);
      }
      int l = 1;
      each(a, _, v) l = lcm(l, a);
      ans += mint(l).Pow(k) * cnt;
      return;
    }
    int i = v.empty() ? 1 : v.back().first;
    for (; i + sum <= n; ++i) {
      if (v.empty() || v.back().first < i) {
        v.eb(i, 1);
        rec(sum + i);
        v.pop_back();
      } else {
        v.back().second++;
        rec(sum + i);
        v.back().second--;
      }
    }
  })(0);
  wt(ans);
}
