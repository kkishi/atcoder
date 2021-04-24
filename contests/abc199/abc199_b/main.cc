#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  int ans = 0;
  rep(x, 1, 1001) {
    bool ok = true;
    rep(i, n) if (x < a[i] || b[i] < x) ok = false;
    if (ok) ++ans;
  }
  wt(ans);
}
