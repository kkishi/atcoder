#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b);
  V<int> c(n);
  cin >> c;
  rep(i, n) if (c[i] == a + b) wt(i + 1);
}
