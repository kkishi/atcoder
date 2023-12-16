#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  vector b(h, vector(w, int(0)));
  cin >> a >> b;
  map<VV<int>, int> dist;
  queue<VV<int>> que;
  auto push = [&](const VV<int>& v, int d) {
    if (dist.count(v)) return;
    dist[v] = d;
    que.push(v);
  };
  push(a, 0);
  while (!que.empty()) {
    auto v = que.front();
    que.pop();
    int d = dist[v];
    if (v == b) {
      wt(d);
      return;
    }
    rep(i, h - 1) {
      swap(v[i], v[i + 1]);
      push(v, d + 1);
      swap(v[i], v[i + 1]);
    }
    rep(i, w - 1) {
      rep(j, h) swap(v[j][i], v[j][i + 1]);
      push(v, d + 1);
      rep(j, h) swap(v[j][i], v[j][i + 1]);
    }
  }
  wt(-1);
}
