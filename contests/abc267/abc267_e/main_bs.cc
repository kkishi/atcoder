#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "graph.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  Graph g(n);
  g.Read(m);

  wt(BinarySearch<int>(accumulate(a), -1, [&](int x) {
    V<int> nc(n);
    queue<int> que;
    rep(i, n) {
      each(c, g[i]) nc[i] += a[c];
      if (nc[i] <= x) que.push(i);
    }
    int cnt = 0;
    while (!que.empty()) {
      int node = que.front();
      que.pop();
      ++cnt;
      each(child, g[node]) {
        if (nc[child] <= x) continue;
        nc[child] -= a[node];
        if (nc[child] <= x) que.push(child);
      }
    }
    return cnt == n;
  }));
}
