#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  int ans = 0;
  rep(i, n) {
    ans += a[i];
    b[i] -= a[i];
  }
  V<int> o, e;
  rep(i, n)(even(i) ? e : o).pb(b[i]);
  sort(o, greater{});
  sort(e, greater{});
  rep(i, n / 2) {
    int x = o[i] + e[i];
    if (x <= 0) break;
    ans += x;
  }
  wt(ans);
}
