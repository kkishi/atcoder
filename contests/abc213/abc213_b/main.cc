#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> a;
  rep(i, n) {
    ints(x);
    a.eb(x, i);
  }
  sort(a, greater{});
  wt(a[1].second + 1);
}
