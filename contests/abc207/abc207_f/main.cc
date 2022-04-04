#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  Graph g(n);
  g.Read();
  V<int> sdp(n);
  vector dp(n, vector(2, vector(2, vector(n + 1, mint(0)))));
  Fix([&](auto rec, int node, int parent) -> void {
    sdp[node] = 1;
    dp[node][0][0][0] = 1;
    dp[node][1][1][1] = 1;
    each(child, g[node]) if (child != parent) {
      rec(child, node);
      sdp[node] += sdp[child];
      vector ep(2, vector(2, vector(n + 1, mint(0))));
      rep(node_has_t, 2) rep(node_protected, 2) rep(node_x, sdp[node] + 1) {
        mint N = dp[node][node_has_t][node_protected][node_x];
        if (N == 0) continue;
        rep(child_has_t, 2) rep(child_protected, 2)
            rep(child_x, sdp[child] + 1) {
          mint C = dp[child][child_has_t][child_protected][child_x];
          if (C == 0) continue;
          int n_node_protected = node_protected | child_has_t;
          int node_newly_protected = !node_protected && n_node_protected;
          int child_newly_proteted = !child_protected && node_has_t;
          int n_node_x =
              node_x + child_x + node_newly_protected + child_newly_proteted;
          ep[node_has_t][n_node_protected][n_node_x] += N * C;
        }
      }
      swap(ep, dp[node]);
    }
  })(0, -1);
  rep(k, n + 1) {
    mint ans = 0;
    rep(i, 2) rep(j, 2) ans += dp[0][i][j][k];
    wt(ans);
  }
}
