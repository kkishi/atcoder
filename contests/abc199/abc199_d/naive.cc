#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "rand.h"

void Main() {
  ints(n, m);
  Graph g(n);
  g.Read(m);
  int ans = 0;
  V<int> color(n);
  Fix([&](auto rec, int depth) {
    if (depth == n) {
      ++ans;
      return;
    }
    V<bool> used(3);
    each(j, g[depth]) if (j < depth) { used[color[j]] = true; }
    rep(c, 3) if (!used[c]) {
      color[depth] = c;
      rec(depth + 1);
    }
  })(0);
  wt(ans);
}
