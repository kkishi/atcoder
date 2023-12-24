#include <bits/stdc++.h>

#include "atcoder.h"
#include "min_segment_tree.h"

void Main() {
  ints(n, k);
  using P = complex<double>;
  ints(sx, sy);
  P s(sx, sy);
  V<P> p;
  rep(n) {
    ints(x, y);
    p.eb(x, y);
  }
  double ans = abs(s - p[0]) + abs(p.back() - s);
  rep(i, n - 1) ans += abs(p[i + 1] - p[i]);
  V<double> dp(n);
  MinSegmentTree<double> t(n);
  for (int i = n - 1; i >= 0; --i) {
    if (i <= n - 1 - k) {
      dp[i] = t.Aggregate(i + 1, i + 1 + k);
    }
    if (i > 0) {
      t.Set(i,
            dp[i] + abs(s - p[i]) + abs(s - p[i - 1]) - abs(p[i] - p[i - 1]));
    }
  }
  ans += dp[0];
  wt(ans);
}
