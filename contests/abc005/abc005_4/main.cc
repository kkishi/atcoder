#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(n);
  vector d(n, vector(n, int(0)));
  cin >> d;

  CumulativeSum2D s(d);

  V<int> maxi(n * n + 1);
  rep(i, n) rep(j, n) rep(k, i + 1) rep(l, j + 1) {
    chmax(maxi[(i - k + 1) * (j - l + 1)], s.Get(k, l, i, j));
  }
  rep(i, n * n) chmax(maxi[i + 1], maxi[i]);

  ints(q);
  rep(q) {
    ints(p);
    wt(maxi[p]);
  }
}
