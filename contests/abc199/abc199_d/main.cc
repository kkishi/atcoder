#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  VV<int> g(n);
  DisjointSet ds(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
    ds.Union(a, b);
  }
  set<int> ids;
  rep(i, n) ids.insert(ds.Find(i));
  int ans = 1;

  V<int> idx(n);
  iota(all(idx), int(0));
  rep(i, n - 1) swap(idx[i], idx[i + rand() % (n - i)]);

  each(id, ids) {
    int cnt = 0;
    V<int> color(n, -1);
    Fix([&](auto rec, int depth) {
      if (depth == n) {
        ++cnt;
        return;
      }
      int I = idx[depth];
      if (ds.Find(I) != id) {
        rec(depth + 1);
        return;
      }
      V<bool> used(3);
      each(j, g[I]) if (color[j] != -1) { used[color[j]] = true; }
      rep(c, 3) if (!used[c]) {
        color[I] = c;
        rec(depth + 1);
      }
      color[I] = -1;
    })(0);
    ans *= cnt;
  }
  wt(ans);
}
