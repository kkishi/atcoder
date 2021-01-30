#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n - 1) if (a[i] == a[i + 1]) {
    ++ans;
    a[i + 1] = 0;
  }
  wt(ans);
}
