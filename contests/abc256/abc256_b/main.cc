#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> b(8);
  rep(i, n) {
    b[0] = 1;
    rrep(j, 4) {
      b[j + a[i]] += b[j];
      b[j] = 0;
    }
  }
  int ans = 0;
  rep(i, 4, 8) ans += b[i];
  wt(ans);
}
