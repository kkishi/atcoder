#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> two(3);
  rep(i, n) {
    int t = 0;
    if (a[i] % 2 == 0) ++t;
    if (a[i] % 4 == 0) ++t;
    two[t]++;
  }
  bool ok = false;
  rep(i, 3) if (two[i] != 0) {
    if ([&](V<int> two) {
          int p = i;
          --two[i];
          rep(j, 1, n) {
            bool ok = false;
            rep(k, 3) if (k + p >= 2 && two[k] > 0) {
              --two[k];
              p = k;
              ok = true;
              break;
            }
            if (!ok) return false;
          }
          return true;
        }(two)) {
      ok = true;
    }
  }
  wt(ok);
}
