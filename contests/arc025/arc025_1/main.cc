#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> d(7), j(7);
  cin >> d >> j;
  int ans = 0;
  rep(i, 7) ans += max(d[i], j[i]);
  wt(ans);
}
