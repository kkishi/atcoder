#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(k);
  cin >> a;
  if (even(k)) {
    int ans = 0;
    rep(i, k / 2) ans += a[i * 2 + 1] - a[i * 2];
    wt(ans);
    return;
  }
  V<int> l(k + 1), r(k + 1);
  for (int i = 2; i <= k; i += 2) {
    l[i] = l[i - 2] + a[i - 1] - a[i - 2];
  }
  for (int i = k - 3; i >= 0; i -= 2) {
    r[i] = r[i + 2] + a[i + 2] - a[i + 1];
  }
  int ans = big;
  for (int i = 0; i <= k; i += 2) {
    chmin(ans, l[i] + r[i]);
  }
  wt(ans);
}
