#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "disjoint_set.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(n, m);
  DisjointSet ds(n);
  WeightedGraph<int> g(n);   // Graph
  WeightedGraph<int> tw(n);  // Tree
  Graph t(n);                // Tree
  VV<int> e;
  rep(m) {
    ints(a, b);
    --a, --b;
    g[a].eb(b, 1);
    g[b].eb(a, 1);
    if (ds.Same(a, b)) {
      e.pb({a, b});
    } else {
      ds.Union(a, b);
      tw[a].eb(b, 1);
      tw[b].eb(a, 1);
      t[a].eb(b);
      t[b].eb(a);
    }
  }
  int M = sz(e);
  map<int, V<optional<int>>> d;
  each(v, e) each(x, v) {
    if (!d.count(x)) d[x] = Dijkstra(g, x).dist;
  }
  vector dp(M, vector(2, vector(1 << M, vector(M, vector(2, big)))));
  rep(i, M) {
    dp[i][0][1 << i][i][0] = 1;  // a -> b
    dp[i][1][1 << i][i][1] = 1;  // b -> a
  }
  rep(mask, 1 << M) {
    rep(I, M) {
      if (hasbit(mask, I)) {
        rep(J, M) {
          if (hasbit(mask, J)) {
            rep(K, M) {
              if (!hasbit(mask, K)) {
                rep(i, 2) rep(j, 2) rep(k, 2) {
                  chmin(dp[I][i][mask | (1 << K)][K][k],
                        dp[I][i][mask][J][j] + *d[e[J][1 - j]][e[K][k]] + 1);
                }
              }
            }
          }
        }
      }
    }
  }
  map<pair<int, int>, int> dist;
  rep(I, M) rep(i, 2) rep(J, M) rep(j, 2) {
    pair<int, int> p{e[I][i], e[J][1 - j]};
    if (!dist.count(p)) dist[p] = big;
    rep(mask, 1 << M) chmin(dist[p], dp[I][i][mask][J][j]);
  }

  RootedTree rt(t, 0);
  V<optional<int>> rd = Dijkstra(tw, 0).dist;

  ints(q);
  rep(q) {
    ints(u, v);
    --u, --v;
    int ans = *rd[u] + *rd[v] - *rd[rt.LCA(u, v)] * 2;
    each(k, V, dist) {
      auto [a, b] = k;
      chmin(ans, *d[a][u] + V + *d[b][v]);
    }
    wt(ans);
  }
}
