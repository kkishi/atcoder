#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, l);
  V<string> s(n);
  cin >> s;
  V<int> st(n);
  rep(i, n) each(e, s[i]) st[i] |= 1 << (e - 'a');
  mint ans = 0;
  rep(mask, 1, 1 << n) {
    int bits = (1 << 26) - 1;
    rep(i, n) if (hasbit(mask, i)) bits &= st[i];
    mint x = mint(popcount(bits)).Pow(l);
    if (even(popcount(mask))) x = -x;
    ans += x;
  }
  wt(ans);
}
