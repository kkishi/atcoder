#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n);
  cin >> x;
  V<int> sx = x;
  sort(sx);
  rep(i, n) {
    int l = n / 2 - 1;
    wt(x[i] <= sx[l] ? sx[l + 1] : sx[l]);
  }
}
