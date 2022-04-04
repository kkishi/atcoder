#include <bits/stdc++.h>
#include <pbds.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  Graph g(n);
  g.Read();
  Set<pair<int, int>> s;
  wt(Fix([&](auto rec, int node, int parent, int depth) -> int {
    s.insert({a[node], node});
    int ret = even(depth) ? -big : big;
    bool leaf = true;
    each(child, g[node]) {
      if (child == parent) continue;
      leaf = false;
      int r = rec(child, node, depth + 1);
      if (even(depth)) {
        chmax(ret, r);
      } else {
        chmin(ret, r);
      }
    }
    if (leaf) {
      auto it = s.find_by_order((sz(s) - 1) / 2);
      if (even(sz(s))) {
        ret = (it->first + next(it)->first) / 2;
      } else {
        ret = it->first;
      }
    }
    s.erase({a[node], node});
    return ret;
  })(0, -1, 0));
}
