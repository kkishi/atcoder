#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;

  const int N = max(a) + 1;
  V<int> b(N + 1);
  rep(i, m)++ b[a[i]];
  int ans;
  rep(i, N + 1) if (b[i] == 0) {
    ans = i;
    break;
  }
  int i = m - 1;
  while (true) {
    ++i;
    if (i == n) break;
    ++b[a[i]];
    --b[a[i - m]];
    if (b[a[i - m]] == 0) chmin(ans, a[i - m]);
  }
  wt(ans);
}
