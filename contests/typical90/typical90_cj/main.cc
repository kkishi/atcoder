#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  Graph g(n);
  g.Read(q);
  map<int, V<int>> seen;
  V<int> idx;
  V<int> ng(n);
  Fix([&](auto rec, int sum, int depth) {
    if (seen.count(sum) && seen[sum] != idx) {
      wt(sz(idx));
      wt(idx);
      auto& jdx = seen[sum];
      wt(sz(jdx));
      wt(jdx);
      exit(0);
    }
    seen[sum] = idx;
    if (depth == n) return;
    if (ng[depth] == 0) {
      each(i, g[depth])++ ng[i];
      idx.pb(depth + 1);
      rec(sum + a[depth], depth + 1);
      idx.pop_back();
      each(i, g[depth])-- ng[i];
    }
    rec(sum, depth + 1);
  })(0, 0);
}
