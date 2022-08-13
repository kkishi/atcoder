#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m, e);
  int N = n + m;
  V<pair<int, int>> es(e);
  cin >> es;
  each(u, v, es)-- u, --v;
  ints(q);
  V<int> x(q);
  cin >> x;
  each(e, x)-- e;
  V<bool> cut(e);
  each(e, x) cut[e] = true;
  DisjointSet ds(N + 1);
  rep(i, m) ds.Union(n + i, N);
  int cnt = 0;
  auto uni = [&](int i, int j) {
    if (ds.Same(i, N) ^ ds.Same(j, N)) {
      cnt += ds.Same(i, N) ? ds.Size(j) : ds.Size(i);
    }
    ds.Union(i, j);
  };
  rep(i, e) if (!cut[i]) {
    auto [u, v] = es[i];
    uni(u, v);
  }
  V<int> ans(q);
  rrep(i, q) {
    ans[i] = cnt;
    auto [u, v] = es[x[i]];
    uni(u, v);
  }
  each(e, ans) wt(e);
}
