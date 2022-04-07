#include <bits/stdc++.h>

#include "atcoder.h"
#include "interval_scheduling.h"

void Main() {
  ints(n, d);
  V<pair<int, int>> v;
  rep(n) {
    ints(l, r);
    v.eb(l - d, r);
  }
  wt(IntervalScheduling(v));
}
