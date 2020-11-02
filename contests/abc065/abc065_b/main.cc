#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int i = 0;
  rep(j, n) {
    i = a[i] - 1;
    if (i == 1) {
      wt(j + 1);
      return;
    }
  }
  wt(-1);
}
