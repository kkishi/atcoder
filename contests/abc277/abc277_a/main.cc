#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> p(n);
  cin >> p;
  rep(i, n) if (p[i] == x) {
    wt(i + 1);
    return;
  }
}
