#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "graph.h"

void Main() {
  ints(n);
  V<int> a(n);
  rep(i, 1, n) cin >> a[i];
  Graph g(n);
  g.Read();
  wt(BinarySearch<int>(0, max(a) + 1, [&](int x) -> int {
    return Fix([&](auto rec, int node, int parent) -> int {
             int cnt = 0;
             each(child, g[node]) if (child != parent) {
               if (a[child] >= x) ++cnt;
               cnt += rec(child, node);
             }
             return max(0, cnt - 1);
           })(0, -1) > 0;
  }));
}
