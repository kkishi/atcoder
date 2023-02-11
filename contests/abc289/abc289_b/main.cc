#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph g(n);
  rep(m) {
    ints(a);
    g[a - 1].eb(a);
  }
  V<int> ans;
  V<bool> seen(n);
  rep(i, n) {
    Fix([&](auto rec, int i) -> void {
      if (seen[i]) return;
      seen[i] = true;
      each(c, g[i]) rec(c);
      ans.eb(i + 1);
    })(i);
  }
  wt(ans);
}
