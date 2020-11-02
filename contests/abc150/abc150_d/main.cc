#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;

  rep(i, n) a[i] /= 2;
  int l = 1;
  rep(i, n) {
    l = l * a[i] / gcd(l, a[i]);
    if (l > m) {
      wt(0);
      return;
    }
  }
  rep(i, n) if (l / a[i] % 2 == 0) {
    wt(0);
    return;
  }
  int ans = 0;
  if (m >= l) {
    ++ans;
    m -= l;
  }
  ans += m / (2 * l);
  wt(ans);
}
