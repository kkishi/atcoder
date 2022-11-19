#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  chmin(k, n);
  V<int> a(n);
  cin >> a;
  V<int> ans;
  rep(i, n - k) ans.eb(a[k + i]);
  rep(k) ans.eb(0);
  wt(ans);
}
