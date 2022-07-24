// This is a fixed version of main.cc.
#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m, v);
  --v;
  WeightedGraph<int> g(n), rg(n);
  vector deg(2, vector(n, int(0)));
  rep(m) {
    ints(a, b, c);
    --a, --b;
    g[a].eb(b, c);
    rg[b].eb(a, c);
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
  set<pair<int, P>> st;
  map<P, int> mp;
  while (true) {
    // Take the smallest candidate.
    if (!st.empty()) {
      auto it = st.begin();
      que.emplace(it->second);
      st.erase(it);
    }
    if (que.empty()) break;
    while (!que.empty()) {
      auto [node, aoki] = que.front();
      que.pop();
      int& d = dp[aoki][node];
      if (d != -1) continue;
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
      each(parent, _, rg[node]) {
        if (--deg[!aoki][parent] == 0) {
          que.emplace(parent, !aoki);
        }
      }
      // The current node represents Aoki's turn and it has a finite value.
      // That means Takahashi's turns leading to this node can be finite.
      // Rememeber such nodes so that we can continue the computation when que
      // becomes empty.
      if (aoki) {
        each(parent, weight, rg[node]) {
          if (dp[!aoki][parent] == -1) {
            P p = {parent, !aoki};
            int d = dp[aoki][node] + weight;
            if (mp.count(p) == 0 || mp[p] > d) {
              mp[p] = d;
              st.emplace(d, p);
            }
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
