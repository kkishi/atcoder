#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, k);
  V<int> h(n);
  cin >> h;
  V<int> d(n, big);
  queue<int> q;
  rep(k) {
    ints(c);
    --c;
    d[c] = 0;
    q.push(c);
  }
  VV<int> to(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    if (h[a] > h[b]) swap(a, b);
    to[a].pb(b);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    each(c, to[x]) if (chmin(d[c], d[x] + 1)) q.push(c);
  }
  each(x, d) wt(x == big ? -1 : x);
}
