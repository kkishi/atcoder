#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<pair<double, double>> g(n);
  rep(m) {
    ints(u, v, b, c);
    g[u - 1].eb(v - 1, pair(b, c));
  }
  wt(BinarySearch<double>(0, big, [&](double x) -> bool {
    V<double> dp(n, -big);
    dp[0] = 0;
    rep(i, n) each(j, w, g[i]) chmax(dp[j], dp[i] + w.first - w.second * x);
    return dp[n - 1] >= 0;
  }));
}
