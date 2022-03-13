#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  V<int> c(n);
  rep(i, n) c[i] = a[i] - b[i];
  sort(c, greater{});
  if (accumulate(c) < 0) {
    wt(-1);
    return;
  }
  int ans = 0;
  int rem = 0;
  rep(i, n) if (c[i] < 0) {
    ++ans;
    rem += c[i];
  }
  rep(i, n) {
    if (rem >= 0) break;
    rem += c[i];
    ++ans;
  }
  wt(ans);
}
