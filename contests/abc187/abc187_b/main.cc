#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  int ans = 0;
  rep(i, n - 1)
      rep(j, i + 1, n) if (abs(y[j] - y[i]) <= abs(x[j] - x[i]))++ ans;
  wt(ans);
}
