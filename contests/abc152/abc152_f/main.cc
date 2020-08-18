#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct Edge {
  int index;
  int dst;
};

ll use[20];

ll DFS(int curr, int dst, int prev, ll used,
       const vector<vector<Edge>>& edges) {
  if (curr == dst) {
    return used;
  }
  for (const Edge& e : edges[curr]) {
    if (e.dst == prev) continue;
    ll res = DFS(e.dst, dst, curr, used | (1LL << e.index), edges);
    if (res > 0) {
      return res;
    }
  }
  return 0;
}

int main() {
  ints(N);
  vector<vector<Edge>> edges(N);
  rep(i, N - 1) {
    ints(a, b);
    --a, --b;
    edges[a].push_back({i, b});
    edges[b].push_back({i, a});
  }
  ints(M);
  rep(i, M) {
    ints(u, v);
    --u, --v;
    use[i] = DFS(u, v, -1, 0, edges);
    dbg(use[i]);
  }
  ll ans = 1LL << (N - 1);
  for (int s = 1; s < (1 << M); ++s) {
    int cnt = 0;
    ll u = 0;
    rep(i, M) {
      if (s & (1 << i)) {
        ++cnt;
        u |= use[i];
      }
    }
    ans -= (cnt % 2 ? 1 : -1) * (1LL << (N - 1 - bitset<64>(u).count()));
  }
  wt(ans);
}
