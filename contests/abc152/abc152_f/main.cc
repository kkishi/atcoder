#include <bits/stdc++.h>

#include "atcoder.h"

struct Edge {
  int index;
  int dst;
};

int use[20];

int DFS(int curr, int dst, int prev, int used, const VV<Edge>& edges) {
  if (curr == dst) {
    return used;
  }
  each(e, edges[curr]) {
    if (e.dst == prev) continue;
    int res = DFS(e.dst, dst, curr, used | (1LL << e.index), edges);
    if (res > 0) {
      return res;
    }
  }
  return 0;
}

void Main() {
  ints(N);
  vector<vector<Edge>> edges(N);
  rep(i, N - 1) {
    ints(a, b);
    --a, --b;
    edges[a].pb({i, b});
    edges[b].pb({i, a});
  }
  ints(M);
  rep(i, M) {
    ints(u, v);
    --u, --v;
    use[i] = DFS(u, v, -1, 0, edges);
    dbg(use[i]);
  }
  int ans = 1LL << (N - 1);
  rep(s, 1, 1 << M) {
    int cnt = 0;
    int u = 0;
    rep(i, M) if (hasbit(s, i)) {
      ++cnt;
      u |= use[i];
    }
    ans -= (even(cnt) ? -1 : 1) * (1LL << (N - 1 - popcount(u)));
  }
  wt(ans);
}
