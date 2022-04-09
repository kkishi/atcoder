#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  g.Read(m);

  int ma = -big;
  rep(i, n) each(j, w, g[i]) chmax(ma, w);

  int ans = 0;
  rep(i, 1, ma) {
    V<int> val(n, -1);
    bool res = Fix([&](auto rec, int node, int x) -> bool {
      if (val[node] != -1) {
        return val[node] == x;
      }
      val[node] = x;
      each(child, w, g[node]) {
        if (w <= x) return false;
        if (!rec(child, w - x)) return false;
      }
      return true;
    })(0, i);
    if (res) ++ans;
  }
  wt(ans);
}
