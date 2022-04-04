#include <bits/stdc++.h>

#include "atcoder.h"
#include "dfs_order.h"

void Main() {
  ints(n, m);
  Graph g(n);
  g.Read(m);
  int ans = 1;
  V<bool> seen(n);
  rep(i, n) if (!seen[i]) {
    V<int> o = DFSOrder(g, i);
    each(e, o) seen[e] = true;
    int cnt = 0;
    V<int> color(n, -1);
    Fix([&](auto rec, int depth) {
      if (depth == sz(o)) {
        ++cnt;
        return;
      }
      V<bool> used(3);
      each(to, g[o[depth]]) if (color[to] != -1) used[color[to]] = true;
      rep(c, 3) if (!used[c]) {
        color[o[depth]] = c;
        rec(depth + 1);
      }
      color[o[depth]] = -1;
    })(0);
    ans *= cnt;
  }
  wt(ans);
}
