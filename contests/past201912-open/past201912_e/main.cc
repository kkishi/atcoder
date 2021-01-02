#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  VV<bool> f(n, V<bool>(n));
  rep(qi, q) {
    ints(s);
    if (s == 1) {
      ints(a, b);
      f[a - 1][b - 1] = true;
    } else if (s == 2) {
      ints(a);
      rep(i, n) if (f[i][a - 1]) f[a - 1][i] = true;
    } else {
      ints(a);
      V<int> v;
      rep(i, n) if (f[a - 1][i]) rep(j, n) if (j != a - 1 && f[i][j])
          v.pb(j);
      for (int i : v) f[a - 1][i] = true;
    }
  }
  rep(i, n) {
    rep(j, n) cout << (f[i][j] ? 'Y' : 'N');
    cout << endl;
  }
}
