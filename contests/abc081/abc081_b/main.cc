#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  while (true) {
    rep(i, n) {
      if (a[i] & 1) {
        wt(ans);
        return;
      }
      a[i] /= 2;
    }
    ++ans;
  }
}
