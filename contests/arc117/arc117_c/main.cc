#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<3>;

void Main() {
  ints(n);
  strings(s);
  V<int> v;
  each(c, s) v.pb(c == 'B' ? 0 : c == 'W' ? 1 : 2);
  mint x = 1;
  int three = 0;
  V<mint> w;
  rep(i, n) {
    if (three > 0) {
      w.pb(0);
    } else {
      w.pb(x);
    }
    if (i == n - 1) break;
    {
      int y = n - 1 - i;
      while (y % 3 == 0) {
        y /= 3;
        ++three;
      }
      x *= y;
    }
    {
      int y = i + 1;
      while (y % 3 == 0) {
        y /= 3;
        --three;
      }
      x /= y;
    }
  }
  dbg(v);
  dbg(w);
  mint ans = 0;
  rep(i, n) ans += v[i] * w[i];
  if (even(n)) ans = -ans;
  wt(ans == 0 ? 'B' : ans == 1 ? 'W' : 'R');
}
