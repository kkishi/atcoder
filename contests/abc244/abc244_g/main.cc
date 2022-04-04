#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph g(n);
  g.Read(m);
  strings(s);
  V<int> ans;
  V<int> p(n);
  V<bool> seen(n, false);
  Fix([&](auto rec, int node, int parent) -> void {
    ans.pb(node);
    p[node] ^= 1;
    seen[node] = true;
    each(child, g[node]) {
      if (!seen[child]) {
        rec(child, node);
        ans.pb(node);
        p[node] ^= 1;
      }
    }
    if (p[node] != (s[node] - '0')) {
      if (parent == -1) {
        p[node] ^= 1;
        ans = V<int>(ans.begin() + 1, ans.end());
      } else {
        ans.pb(parent);
        p[parent] ^= 1;
        ans.pb(node);
        p[node] ^= 1;
      }
    }
  })(0, -1);
  wt(sz(ans));
  each(e, ans)++ e;
  wt(ans);
}
