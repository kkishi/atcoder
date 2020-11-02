#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector<vector<int>> g(n + 1);
  rep(i, m) {
    ints(u, v);
    g[u].push_back(v);
  }
  ints(s, t);
  vector<vector<bool>> visited(n + 1, vector<bool>(3));
  visited[s][0] = true;
  queue<tuple<int, int, int>> que;
  que.push({s, 0, 0});
  while (!que.empty()) {
    auto [node, step, dist] = que.front();
    que.pop();
    if (node == t && step == 0) {
      wt(dist);
      return;
    }
    for (int child : g[node]) {
      int nstep = step + 1;
      int ndist = dist;
      if (nstep == 3) {
        nstep = 0;
        ++ndist;
      }
      if (visited[child][nstep]) continue;
      visited[child][nstep] = true;
      que.push({child, nstep, ndist});
    }
  }
  wt(-1);
}
