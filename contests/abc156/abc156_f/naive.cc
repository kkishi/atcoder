#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k, q);
  V<int> d(k);
  cin >> d;
  rep(q) {
    ints(n, x, m);
    int ans = 0;
    int a = x % m;
    dbg(a);
    rep(i, n - 1) {
      int b = (a + d[i % k]) % m;
      if (a < b) ++ans;
      a = b;
      dbg(a);
    }
    wt(ans);
  }
}
