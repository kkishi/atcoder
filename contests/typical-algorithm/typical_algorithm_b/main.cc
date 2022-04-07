#include <bits/stdc++.h>

#include "atcoder.h"
#include "interval_scheduling.h"

void Main() {
  ints(n);
  V<pair<int, int>> v;
  rep(n) {
    ints(a, b);
    v.eb(a, b + 1);
  }
  wt(IntervalScheduling(v));
}
