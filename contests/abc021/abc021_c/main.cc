#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, a, b, m);
  --a, --b;
  VV<int> to(n);
  rep(m) {
    ints(x, y);
    --x, --y;
    to[x].pb(y);
    to[y].pb(x);
  }

  V<int> dist(n, big);
  V<mint> cnt(n);
  dist[a] = 0;
  cnt[a] = 1;
  queue<int> que;
  que.push(a);
  while (!que.empty()) {
    int here = que.front();
    que.pop();
    for (int there : to[here]) {
      if (chmin(dist[there], dist[here] + 1)) {
        dist[there] = dist[here] + 1;
        cnt[there] = cnt[here];
        que.push(there);
      } else if (dist[there] == dist[here] + 1) {
        cnt[there] += cnt[here];
      }
    }
  }
  wt(cnt[b]);
}
