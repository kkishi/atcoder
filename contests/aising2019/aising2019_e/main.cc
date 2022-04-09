#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  Graph g(n);
  g.Read();
  V<int> sdp(n);
  vector dp(n, vector(2, vector(n, big)));
  Fix([&](auto rec, int node, int parent) -> void {
    sdp[node] = 1;
    if (a[node] < 0) {
      dp[node][1] = {a[node]};
    } else {
      dp[node][0] = {a[node]};
    }
    each(child, g[node]) if (child != parent) {
      rec(child, node);
      vector ndp(2, vector(n, big));
      rep(node_pc, 2) rep(node_cuts, sdp[node]) {
        int node_dp = dp[node][node_pc][node_cuts];
        if (node_dp == big) continue;
        rep(child_pc, 2) rep(child_cuts, sdp[child]) {
          int child_dp = dp[child][child_pc][child_cuts];
          if (child_dp == big) continue;
          // do not cut
          {
            int pc = node_pc | child_pc;
            int cuts = node_cuts + child_cuts;
            chmin(ndp[pc][cuts], node_dp + child_dp);
          }
          // cut
          if (!child_pc || child_dp < 0) {
            int pc = node_pc;
            int cuts = node_cuts + child_cuts + 1;
            chmin(ndp[pc][cuts], node_dp);
          }
        }
      }
      sdp[node] += sdp[child];
      swap(dp[node], ndp);
    }
  })(0, -1);
  int ans = big;
  rep(i, n) if (dp[0][0][i] != big) chmin(ans, i);
  rep(i, n) if (dp[0][1][i] < 0) chmin(ans, i);
  wt(ans);
}
