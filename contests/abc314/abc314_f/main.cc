#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);

  // Construct the tree.
  Graph g(n * 2 - 1);
  DisjointSet ds(n);
  V<int> idx(n);
  rep(i, n) idx[i] = i;
  V<int> size(n * 2 - 1, 1);
  rep(i, n - 1) {
    ints(p, q);
    --p, --q;
    p = ds.Find(p);
    q = ds.Find(q);
    int I = n + i;
    int pi = idx[p];
    int qi = idx[q];
    g[I].eb(pi);
    g[I].eb(qi);
    idx[ds.Union(p, q)] = I;
    size[I] = size[pi] + size[qi];
  }

  // DP on the tree.
  vector dp(n * 2 - 1, mint(0));
  Fix([&](auto rec, int node, mint x) -> void {
    dp[node] = x;
    if (g[node].empty()) return;
    int i = g[node][0];
    int j = g[node][1];
    rec(i, x + mint(size[i]) / mint(size[node]));
    rec(j, x + mint(size[j]) / mint(size[node]));
  })(n * 2 - 2, 0);
  wt(vector(dp.begin(), dp.begin() + n));
}
