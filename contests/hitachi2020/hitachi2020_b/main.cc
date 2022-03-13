#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(A, B, m);
  V<int> a(A), b(B);
  cin >> a >> b;
  int ans = min(a) + min(b);
  rep(m) {
    ints(x, y, c);
    chmin(ans, a[x - 1] + b[y - 1] - c);
  }
  wt(ans);
}
