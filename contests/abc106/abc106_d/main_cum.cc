#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(n, m, q);

  vector trains(n + 1, vector(n + 1, int(0)));
  rep(m) {
    ints(l, r);
    trains[n - l][r]++;
  }

  CumulativeSum2D sum(trains);
  rep(q) {
    ints(p, q);
    wt(sum.Get(n - p, q));
  }
}
