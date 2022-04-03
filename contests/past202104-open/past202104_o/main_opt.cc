#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "disjoint_set.h"
#include "graph.h"
#include "lca.h"

int dp[12][2][1 << 12][12][2];

void Main() {
  ints(n, m);
  DisjointSet ds(n);
  WeightedGraph<int> g(n);  // Graph
  WeightedGraph<int> t(n);  // Tree
  V<pair<int, int>> e;
  rep(m) {
    ints(a, b);
    --a, --b;
    g[a].eb(b, 1);
    g[b].eb(a, 1);
    if (ds.Same(a, b)) {
      e.eb(a, b);
    } else {
      ds.Union(a, b);
      t[a].eb(b, 1);
      t[b].eb(a, 1);
    }
  }
  int M = sz(e);
  // map<int, V<optional<int>>> d;
  map<int, V<int>> d;
  each(a, b, e) {
    if (!d.count(a)) {
      V<int> v;
      each(e, Dijkstra(g, a).dist) v.pb(*e);
      d[a] = v;
    }
    if (!d.count(b)) {
      V<int> v;
      each(e, Dijkstra(g, b).dist) v.pb(*e);
      d[b] = v;
    }
  }
  RootedTree rt(t, 0);
  V<optional<int>> rd = Dijkstra(t, 0).dist;

  rep(i, M) rep(j, 2) rep(k, 1 << M) rep(l, M) rep(m, 2) dp[i][j][k][l][m] =
      big;
  rep(i, M) {
    dp[i][0][1 << i][i][0] = 1;  // a -> b
    dp[i][1][1 << i][i][1] = 1;  // b -> a
  }
  rep(mask, 1 << M) {
    rep(i, M) {
      if (hasbit(mask, i)) {
        auto [a, b] = e[i];
        const V<int>& da = d[a];
        const V<int>& db = d[b];
        rep(j, M) {
          if (!hasbit(mask, j)) {
            auto [c, D] = e[j];
            rep(k, M) rep(l, 2) {
              chmin(dp[k][l][mask | (1 << j)][j][0],
                    min(dp[k][l][mask][i][0] + db[c],    // a b -> c d
                        dp[k][l][mask][i][1] + da[c]) +  // b a -> c d
                        1);
              chmin(dp[k][l][mask | (1 << j)][j][1],
                    min(dp[k][l][mask][i][0] + db[D],    // a b -> d c
                        dp[k][l][mask][i][1] + da[D]) +  // b a -> d c
                        1);
            }
          }
        }
      }
    }
  }

  ints(q);
  rep(q) {
    ints(u, v);
    --u, --v;
    int ans = *rd[u] + *rd[v] - *rd[rt.LCA(u, v)] * 2;
    rep(mask, 1 << M) {
      rep(i, M) {
        if (hasbit(mask, i)) {
          auto [a, b] = e[i];
          rep(j, M) rep(k, 2) {
            auto [c, D] = e[j];
            chmin(ans, d[c][u] + dp[j][0][mask][i][0] +
                           d[b][v]);  // u -> ... -> a -> b -> v
            chmin(ans, d[D][u] + dp[j][1][mask][i][0] +
                           d[b][v]);  // u -> ... -> a -> b -> v
            chmin(ans, d[c][u] + dp[j][0][mask][i][1] +
                           d[a][v]);  // u -> ... -> a -> b -> v
            chmin(ans, d[D][u] + dp[j][1][mask][i][1] +
                           d[a][v]);  // u -> ... -> a -> b -> v
          }
        }
      }
    }
    wt(ans);
  }
}
