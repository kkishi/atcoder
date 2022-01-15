#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, n);
  queue<int> que;
  que.push(1);
  map<int, int> dist;
  dist[1] = 0;
  int t = 0;
  for (int i = n; i; i /= 10, ++t)
    ;
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    int T = 0;
    for (int i = x; i; i /= 10, ++T)
      ;
    if (T > t) continue;
    {
      int y = x * a;
      if (!dist.count(y)) {
        dist[y] = dist[x] + 1;
        que.push(y);
      }
    }
    if (x >= 10 && x % 10 != 0) {
      int z = 1;
      rep(T - 1) z *= 10;
      int y = z * (x % 10) + x / 10;
      if (!dist.count(y)) {
        dist[y] = dist[x] + 1;
        que.push(y);
      }
    }
  }
  if (dist.count(n)) {
    wt(dist[n]);
  } else {
    wt(-1);
  }
}
