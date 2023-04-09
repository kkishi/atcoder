#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d);
  V<int> t(n);
  cin >> t;
  rep(i, n - 1) if (t[i + 1] - t[i] <= d) {
    wt(t[i + 1]);
    return;
  }
  wt(-1);
}
