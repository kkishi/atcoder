#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, q);
  V<int> x(q), y(q), z(q), w(q);
  rep(i, q) cin >> x[i] >> y[i] >> z[i] >> w[i];
  mint ans = 1;
  rep(i, 60) {
    mint cnt = 0;
    rep(mask, 1 << n) {
      bool ok = true;
      rep(j, q) {
        auto f = [&](int i) { return hasbit(mask, i - 1); };
        if ((f(x[j]) | f(y[j]) | f(z[j])) != hasbit(w[j], i)) ok = false;
      }
      if (ok) ++cnt;
    }
    ans *= cnt;
  }
  wt(ans);
}
