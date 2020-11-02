#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b);
  V<int> x(n);
  cin >> x;
  sort(all(x));
  int ans = 0;
  rep(i, n - 1) ans += min(b, a * (x[i + 1] - x[i]));
  wt(ans);
}
