#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  Graph g(n);
  g.Read();

  V<int> sdp(n);
  vector dp(n, vector(2, vector(n + 1, mint(0))));
  Fix([&](auto rec, int node, int parent) -> void {
    sdp[node] = 1;
    dp[node][0][0] = 1;  // Do not use
    dp[node][1][1] = 1;  // Use
    each(child, g[node]) if (child != parent) {
      rec(child, node);
      vector ndp(2, vector(n + 1, mint(0)));
      rep(use_node, 2) rep(node_size, sdp[node] + 1) {
        mint node_dp = dp[node][use_node][node_size];
        if (node_dp == 0) continue;
        rep(use_child, 2) rep(child_size, sdp[child] + 1) {
          mint child_dp = dp[child][use_child][child_size];
          if (child_dp == 0) continue;
          int total_size = node_size + child_size;
          if (use_node && use_child) --total_size;
          ndp[use_node][total_size] += node_dp * child_dp;
        }
      }
      sdp[node] += sdp[child];
      swap(dp[node], ndp);
    }
  })(0, -1);
  rep(x, 1, n + 1) wt(dp[0][0][x] + dp[0][1][x]);
}
