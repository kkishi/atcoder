#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(m);
  Graph g(9);
  g.Read(m);
  V<int> v;
  rep(8) {
    ints(p);
    v.eb(p - 1);
  }
  map<V<int>, int> dist;
  queue<V<int>> que;
  dist[v] = 0;
  que.push(v);
  while (!que.empty()) {
    V<int> v = que.front();
    que.pop();
    int d = dist[v];
    V<int> b(9, -1);
    rep(i, 8) b[v[i]] = i;
    rep(i, 9) {
      if (b[i] != -1) {
        each(j, g[i]) {
          if (b[j] == -1) {
            V<int> nv = v;
            nv[b[i]] = j;
            if (!dist.count(nv)) {
              dist[nv] = d + 1;
              que.push(nv);
            }
          }
        }
      }
    }
  }
  v.clear();
  rep(i, 8) v.pb(i);
  if (dist.count(v)) {
    wt(dist[v]);
  } else {
    wt(-1);
  }
}
