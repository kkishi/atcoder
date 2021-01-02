#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(i, n) {
    while (even(a[i])) {
      a[i] /= 2;
      ++ans;
    }
  }
  wt(ans);
}
