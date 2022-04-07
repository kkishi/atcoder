#include <bits/stdc++.h>

#include "atcoder.h"
#include "interval_scheduling.h"

void Main() {
  ints(_, m);
  vector<pair<int, int>> v;
  rep(i, m) {
    ints(a, b);
    v.eb(a, b);
  }
  wt(IntervalScheduling(v));
}
