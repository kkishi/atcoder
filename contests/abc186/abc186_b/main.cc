#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<int> a(h * w);
  cin >> a;
  int m = *min_element(all(a));
  int ans = 0;
  rep(i, sz(a)) ans += a[i] - m;
  wt(ans);
}
