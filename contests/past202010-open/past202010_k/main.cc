#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<int(1e9)>;

void Main() {
  ints(k);
  VV<int> v(k, V<int>(20));
  V<int> u(k);
  rep(i, k) {
    ints(n);
    rep(n) {
      ints(a);
      --a;
      rep(j, a + 1, 20) u[i] += v[i][j];
      ++v[i][a];
    }
  }
  mint ans = 0;
  V<int> s(20);
  ints(q);
  rep(q) {
    ints(b);
    --b;
    ans += u[b];
    rep(i, 20) rep(j, i + 1, 20) ans += v[b][i] * s[j];
    rep(i, 20) s[i] += v[b][i];
  }
  wt(ans);
}
