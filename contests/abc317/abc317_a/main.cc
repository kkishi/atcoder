#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, h, x);
  V<int> p(n);
  cin >> p;
  rep(i, n) if (h + p[i] >= x) {
    wt(i + 1);
    return;
  }
}
