#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();

  int ma = -big;
  V<int> result(n);

  rep(root, n) {
    vector dp(n, vector(2, int(0)));
    Fix([&](auto rec, int node, int parent) -> void {
      each(child, g[node]) if (child != parent) {
        rec(child, node);
        vector ndp(2, int(0));
        rep(nu, 2) rep(cu, 2) {
          int sum = dp[node][nu] + dp[child][cu];
          chmax(ndp[nu], sum);
          if (!nu && !cu) {
            chmax(ndp[1], sum + 1);
          }
        }
        swap(dp[node], ndp);
      }
    })(root, -1);
    chmax(ma, max(dp[root]));
    result[root] = dp[root][0];
  }

  wt(count(all(result), ma));
}
