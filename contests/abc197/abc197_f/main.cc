#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<char> v(n);
  v.Read(m);
  vector dist(n, vector(n, big));
  dist[0][n - 1] = 0;
  low_priority_queue<tuple<int, int, int>> que;
  que.emplace(0, 0, n - 1);
  int ans = big;
  while (!que.empty()) {
    auto [d, i, j] = que.top();
    que.pop();
    if (i == j) chmin(ans, d);
    each(ni, c, v[i]) if (ni == j) chmin(ans, d + 1);
    each(ni, nic, v[i]) each(nj, njc, v[j]) {
      if (nic == njc) {
        if (chmin(dist[ni][nj], dist[i][j] + 2)) {
          que.emplace(dist[ni][nj], ni, nj);
        }
      }
    }
  }
  if (ans == big) ans = -1;
  wt(ans);
}
