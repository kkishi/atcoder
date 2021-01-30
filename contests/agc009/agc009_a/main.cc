#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  int ans = 0;
  rrep(i, n) {
    int x = (a[i] + ans) % b[i];
    ans += x == 0 ? 0 : (b[i] - x);
  }
  wt(ans);
}
