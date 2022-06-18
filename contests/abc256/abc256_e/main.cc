#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  V<int> x(n), c(n);
  cin >> x >> c;
  each(e, x)-- e;
  V<int> in(n);
  each(e, x)++ in[e];

  queue<int> que;
  rep(i, n) if (in[i] == 0) que.push(i);
  while (!que.empty()) {
    int i = que.front();
    que.pop();
    if (--in[x[i]] == 0) {
      que.push(x[i]);
    }
  }

  DisjointSet ds(n);
  rep(i, n) if (in[i] != 0) ds.Union(i, x[i]);
  map<int, int> mp;
  rep(i, n) if (ds.Size(i) > 1) mp[ds.Find(i)] = big;
  rep(i, n) if (ds.Size(i) > 1) chmin(mp[ds.Find(i)], c[i]);
  int ans = 0;
  each(_, e, mp) ans += e;
  wt(ans);
}
