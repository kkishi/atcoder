#include <bits/stdc++.h>

#include "atcoder.h"
#include "min_segment_tree.h"

void Main() {
  ints(n, m);
  V<int> a(n), c(n);
  cin >> a >> c;
  set<int> st;
  rep(m) {
    ints(x);
    st.insert(x - 1);
  }

  MinSegmentTree<int> t(n);
  rep(i, n) t.Set(i, c[i]);

  vector dp(n + 1, vector(n + 1, big));
  dp[0][0] = 0;
  rep(i, n) rep(j, i + 1) {
    // Buy
    chmin(dp[i + 1][j + 1], dp[i][j] + a[i] + t.Aggregate(i - j, i + 1));
    // Don't buy
    if (!st.count(i)) chmin(dp[i + 1][j], dp[i][j]);
  }
  wt(min(dp[n]));
}
