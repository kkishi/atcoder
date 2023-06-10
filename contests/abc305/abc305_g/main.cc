#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  V<string> s(m);
  cin >> s;
  auto check = [&](int mask, int l) {
    string t;
    rep(i, l) t += (char)('a' + hasbit(mask, i));
    int ok = 1;
    each(e, s) if (t.find(e) != string::npos) ok = 0;
    return ok;
  };
  if (n < 6) {
    int ans = 0;
    rep(mask, 1 << n) ans += check(mask, n);
    wt(ans);
  } else {
    const int N = 64;
    using mat = Matrix<mint, N, N>;
    using vec = Matrix<mint, N, 1>;
    vec ini;
    rep(mask, 1 << 6) ini[mask][0] = check(mask, 6);
    mat m;
    rep(mask, 1 << 6) {
      if (check(mask, 6)) {
        rep(i, 2) {
          int mask2 = (mask << 1) | i;
          mask2 &= (1 << 6) - 1;
          m[mask2][mask] = check(mask2, 6);
        }
      }
    }
    vec res = Mult(Pow(m, n - 6), ini);
    mint ans = 0;
    rep(i, 1 << 6) ans += res[i][0];
    wt(ans);
  }
}
