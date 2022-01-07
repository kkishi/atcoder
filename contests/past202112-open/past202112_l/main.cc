#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, p);
  V<int> a(n);
  cin >> a;
  V<int> lds;
  rep(i, n) {
    if (a[i] + i > p || a[i] - (n - 1 - i) < 0) continue;
    int b = a[i] + i;
    auto it = lower_bound(all(lds), b - 1, greater{});
    if (it == lds.end()) {
      lds.pb(b);
    } else {
      *it = b;
    }
  }
  wt(n - sz(lds));
}
