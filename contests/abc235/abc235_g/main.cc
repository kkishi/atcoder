#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

unordered_map<int64_t, mint> memo;

mint f(int x, int y) {
  if (x == y) {
    return mint(2).Pow(x);
  }
  auto [it, ok] = memo.emplace((x << 32) | y, mint(0));
  if (ok) {
    it->second = f(x - 1, y) * 2 - mint::Comb(x - 1, y);
  }
  return it->second;
}

void Main() {
  ints(n, a, b, c);
  mint ans = 0;
  rep(i, n + 1) {
    mint x =
        f(i, min(i, a)) * f(i, min(i, b)) * f(i, min(i, c)) * mint::Comb(n, i);
    if (!even(n - i)) x = -x;
    ans += x;
  }
  wt(ans);
}
