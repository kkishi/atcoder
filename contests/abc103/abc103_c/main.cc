#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n) ans += a[i] - 1;
  wt(ans);
}
