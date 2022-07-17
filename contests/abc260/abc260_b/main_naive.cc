#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y, z);
  V<int> a(n), b(n);
  cin >> a >> b;
  V<bool> ok(n);
  auto f = [&](int x, auto g) {
    rep(x) {
      int i = -1;
      rep(j, n) if (!ok[j] && (i == -1 || g(i) < g(j))) i = j;
      if (i != -1) ok[i] = true;
    }
  };
  f(x, [&](int i) { return a[i]; });
  f(y, [&](int i) { return b[i]; });
  f(z, [&](int i) { return a[i] + b[i]; });
  rep(i, n) if (ok[i]) wt(i + 1);
}
