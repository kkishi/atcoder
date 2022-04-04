#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph to(n);
  to.Read();
  V<int> c(n);
  cin >> c;
  sort(c);

  int ci = 0;
  V<int> ans(n);
  Fix([&](auto dfs, int n, int p) -> void {
    for (int c : to[n]) {
      if (c == p) continue;
      dfs(c, n);
    }
    ans[n] = c[ci];
    ++ci;
  })(0, -1);

  wt(accumulate(c.begin(), c.end() - 1, 0));
  wt(ans);
}
