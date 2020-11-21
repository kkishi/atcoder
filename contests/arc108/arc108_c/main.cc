#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

struct E {
  int n;
  int c;
};

void Main() {
  ints(n, m);
  VV<E> to(n);
  DisjointSet ds(n);
  rep(m) {
    ints(u, v, c);
    --u, --v;
    if (ds.Same(u, v)) continue;
    ds.Union(u, v);
    to[u].push_back({v, c});
    to[v].push_back({u, c});
  }
  V<int> ans(n);
  Fix([&](auto rec, int node, int parent, int edge_color,
          int parent_color) -> int {
    int color = -1;
    if (edge_color != -1) {
      if (parent_color != edge_color) {
        color = edge_color;
      }
    }
    set<int> used_colors;
    if (parent_color != -1) used_colors.insert(parent_color);
    for (auto [child, edge_color] : to[node]) {
      if (child == parent) continue;
      used_colors.insert(rec(child, node, edge_color, color));
    }
    if (color == -1) {
      for (int uc : used_colors) {
        if (1 <= uc - 1 && !used_colors.count(uc - 1)) {
          color = uc - 1;
          break;
        }
        if (uc + 1 <= n && !used_colors.count(uc + 1)) {
          color = uc + 1;
          break;
        }
      }
    }
    assert(color != -1);
    ans[node] = color;
    return color;
  })(0, -1, -1, -1);
  rep(i, n) wt(ans[i]);
}
