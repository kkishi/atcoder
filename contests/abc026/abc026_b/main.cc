#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> r(n);
  cin >> r;
  sort(all(r), greater());
  int ans = 0;
  rep(i, n) {
    int r2 = r[i] * r[i];
    if (i & 1) r2 = -r2;
    ans += r2;
  }
  wt(3.14159265358979 * ans);
}
