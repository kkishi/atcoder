#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, T);
  V<int> t(n);
  cin >> t;
  int ans = T;
  rep(i, n - 1) ans += min(T, t[i + 1] - t[i]);
  wt(ans);
}
