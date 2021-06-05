#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, p, q);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n - 4) rep(j, i + 1, n - 3) rep(k, j + 1, n - 2) rep(l, k + 1, n - 1)
      rep(m, l + 1, n) {
    auto f = [&](int x, int i) { return x * a[i] % p; };
    int x = 1;
    x = f(x, i);
    x = f(x, j);
    x = f(x, k);
    x = f(x, l);
    x = f(x, m);
    if (x == q) ++ans;
  }
  wt(ans);
}
