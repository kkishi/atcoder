#include <bits/stdc++.h>

#include "atcoder.h"
#include "count.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, k);

  V<int> a(n);
  cin >> a;

  int zero = count(all(a), 0);

  V<int> b;
  each(e, a) if (e != 0) b.eb(e);
  sort(b);

  mint ans = 0;
  rep(x, 1, m + 1) {
    int lt = CountLT(b, x);
    int gt = CountGT(b, x);

    int l = (k - 1);
    if (lt > l) continue;  // A_k is less than x.
    int r = (n - k);
    if (gt > r) continue;  // A_k is greater than x.

    mint ng = 0;
    // 1) When A_k is less than x?
    {
      // If there are cnt (>= lrem) elements that are less than x, A_k is less
      // than x.
      int lrem = (k - 1) - lt;
      rep(cnt, lrem + 1, zero + 1) {
        ng += mint::Comb(zero, cnt) * mint(x - 1).Pow(cnt) *
              mint(m - x + 1).Pow(zero - cnt);
      }
    }
    // 2) When A_k is greater than x?
    {
      // If there are cnt (>= rrem) elements that are greater than x, A_k is
      // greater than x.
      int rrem = (n - k) - gt;
      rep(cnt, rrem + 1, zero + 1) {
        ng += mint::Comb(zero, cnt) * mint(m - x).Pow(cnt) *
              mint(x).Pow(zero - cnt);
      }
    }
    // 1) and 2) don't overlap, so we can sum them up and subtract from 1.
    mint ok = 1 - ng / mint(m).Pow(zero);
    ans += x * ok;
  }
  wt(ans);
}
