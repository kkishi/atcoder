#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> a(n), b(m);
  cin >> a >> b;
  wt([&] {
    rep(i, n - m + 1) rep(j, sz(a[0]) - sz(b[0]) + 1) {
      bool ok = true;
      rep(k, m) rep(l, sz(b[0])) if (a[i + k][j + l] != b[k][l]) ok = false;
      if (ok) return true;
    }
    return false;
  }());
}
