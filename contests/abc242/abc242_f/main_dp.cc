#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

map<tuple<int, int, int>, mint> memo;

mint Count(int r, int c, int x) {
  if (r * c < x) return 0;
  if (r > c) swap(r, c);
  auto [it, ok] = memo.insert({{r, c, x}, mint(0)});
  if (ok) {
    mint ret = mint::Comb(r * c, x);
    rep(i, r + 1) rep(j, c + 1) {
      if (i == r && j == c) continue;
      ret -= Count(i, j, x) * mint::Comb(r, i) * mint::Comb(c, j);
    }
    it->second = ret;
  }
  return it->second;
}

void Main() {
  ints(n, m, b, w);
  mint ans = 0;
  rep(br, 1, b + 1) rep(wr, 1, min(n - br, w) + 1) {
    mint r = mint::Comb(n, br) * mint::Comb(n - br, wr);
    rep(bc, 1, b + 1) rep(wc, 1, min(m - bc, w) + 1) {
      mint c = mint::Comb(m, bc) * mint::Comb(m - bc, wc);
      ans += r * c * Count(br, bc, b) * Count(wr, wc, w);
    }
  }
  wt(ans);
}
