#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int N = min(20, n);
  V<int> seen(200, -1);
  rep(mask, 1, 1 << N) {
    int sum = 0;
    rep(i, N) if (hasbit(mask, i)) {
      sum += a[i];
      sum %= 200;
    }
    if (seen[sum] != -1) {
      V<int> x;
      rep(i, N) if (hasbit(seen[sum], i)) x.pb(i + 1);
      V<int> y;
      rep(i, N) if (hasbit(mask, i)) y.pb(i + 1);
      wt("Yes");
      cout << sz(x) << " ";
      wt(x);
      cout << sz(y) << " ";
      wt(y);
      return;
    } else {
      seen[sum] = mask;
    }
  }
  wt("No");
}
