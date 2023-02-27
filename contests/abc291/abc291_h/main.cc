#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();

  V<bool> removed(n, false);
  V<int> ans(n, -1);
  Fix([&](auto decompose, int node) -> int {
    // Calculate the size of the subtree to which node belongs.
    int subtree_size = 0;
    Fix([&](auto rec, int node, int parent) -> void {
      ++subtree_size;
      each(child, g[node]) if (!removed[child] && child != parent) {
        rec(child, node);
      }
    })(node, -1);

    // Find a centroid of the subtree to which node belongs.
    int centroid;
    Fix([&](auto rec, int node, int parent) -> int {
      bool ok = true;
      int ret = 1;  // Size of the descendants of node.
      each(child, g[node]) if (!removed[child] && child != parent) {
        int res = rec(child, node);
        ret += res;
        if (res > subtree_size / 2) ok = false;
      }
      if ((subtree_size - ret) > subtree_size / 2) ok = false;
      if (ok) centroid = node;
      return ret;
    })(node, -1);

    removed[centroid] = true;

    each(child, g[centroid]) if (!removed[child]) {
      int child_centroid = decompose(child);
      ans[child_centroid] = centroid + 1;
    }
    return centroid;
  })(0);
  wt(ans);
}
