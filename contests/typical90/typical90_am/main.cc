#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();
  int ans = 0;
  Fix([&](auto rec, int node, int parent) -> int {
    int cnt = 1;
    each(child, g[node]) if (child != parent) cnt += rec(child, node);
    ans += (n - cnt) * cnt;
    return cnt;
  })(0, -1);
  wt(ans);
}
