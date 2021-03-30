#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  VV<int> c(h, V<int>(w));
  cin >> c;

  auto search = [&](const VV<int>& init) {
    map<VV<int>, int> dist;
    dist[init] = 0;
    queue<VV<int>> que;
    que.push(init);
    while (!que.empty()) {
      VV<int> here = que.front();
      que.pop();
      int d = dist[here];
      if (d == 12) continue;
      rep(i, h) rep(j, w) if (here[i][j] == 0) {
        each(ni, nj, adjacent(i, j)) {
          if (inside(ni, nj, h, w)) {
            swap(here[i][j], here[ni][nj]);
            if (auto [_, ok] = dist.insert({here, d + 1}); ok) {
              que.push(here);
            }
            swap(here[i][j], here[ni][nj]);
          }
        }
      }
    }
    return dist;
  };

  map<VV<int>, int> f = search(c);

  VV<int> e(h, V<int>(w));
  rep(i, h * w - 1) e[i / w][i % w] = i + 1;
  map<VV<int>, int> b = search(e);

  int ans = 24;
  for (auto [k, v] : f) {
    auto it = b.find(k);
    if (it != b.end()) {
      chmin(ans, v + it->second);
    }
  }
  wt(ans);
}
