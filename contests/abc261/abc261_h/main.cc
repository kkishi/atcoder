// This solution got AC during the contest but fails with after_contest cases.
#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m, v);
  --v;
  WeightedGraph<int> g(n);
  Graph rg(n);
  vector deg(2, vector(n, int(0)));
  rep(m) {
    ints(a, b, c);
    --a, --b;
    g[a].eb(b, c);
    rg[b].eb(a);
    rep(i, 2)++ deg[i][a];
  }
  vector dp(2, vector(n, int(-1)));
  using P = pair<int, int>;
  queue<P> que;
  rep(i, n) if (deg[0][i] == 0) {
    rep(j, 2) {
      que.emplace(i, j);
      dp[j][i] = 0;
    }
  }
  set<P> st;
  while (true) {
    each(e, st) que.emplace(e);
    st.clear();
    if (que.empty()) break;
    while (!que.empty()) {
      auto [node, aoki] = que.front();
      que.pop();
      if (!g[node].empty()) {
        int& d = dp[aoki][node];
        d = aoki ? -big : big;
        each(child, weight, g[node]) {
          int D = dp[!aoki][child];
          if (D == -1) continue;
          int c = weight + D;
          if (aoki) {
            chmax(d, c);
          } else {
            chmin(d, c);
          }
        }
      }
      each(parent, rg[node]) {
        if (--deg[!aoki][parent] == 0) {
          que.emplace(parent, !aoki);
        }
      }
      // The current node represents Aoki's turn and it has a finite value.
      // That means Takahashi's turns leading to this node can be finite.
      // Rememeber such nodes so that we can continue the computation when que
      // becomes empty.
      if (aoki) {
        each(parent, rg[node]) {
          if (dp[!aoki][parent] == -1) {
            st.emplace(parent, !aoki);
          }
        }
      }
    }
  }
  if (dp[0][v] != -1) {
    wt(dp[0][v]);
  } else {
    wt("INFINITY");
  }
}
