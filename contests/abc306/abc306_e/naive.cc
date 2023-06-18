#include <bits/stdc++.h>

#include "atcoder.h"
#include "twosets.h"

void Main() {
  ints(n, k, q);
  V<int> a(n);
  rep(q) {
    ints(x, y);
    a[x - 1] = y;
    V<int> b = a;
    sort(b);
    int ans = 0;
    rep(i, k) ans += b[n - 1 - i];
    wt(ans);
  }
}
