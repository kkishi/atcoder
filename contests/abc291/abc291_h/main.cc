#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();

  V<bool> removed(n, false);
  V<int> ans(n, -1);
  V<int> sizes(n);
  Fix([&](auto rec, int node, int subtree_size) -> int {
    // Find a centroid of the subtree to which node belongs.
    int centroid;
    Fix([&](auto findCentroid, int node, int parent) -> int {
      bool ok = true;
      int ret = 1;  // Size of the descendants of node.
      each(child, g[node]) if (!removed[child] && child != parent) {
        int res = findCentroid(child, node);
        ret += res;
        if (res > subtree_size / 2) ok = false;
      }
      if ((subtree_size - ret) > subtree_size / 2) ok = false;
      if (ok) centroid = node;
      return ret;
    })(node, -1);

    removed[centroid] = true;

    // Re-calculate the sizes of the subtrees newly created by removing the
    // centroid.
    Fix([&](auto rec, int node, int parent) -> void {
      sizes[node] = 1;
      each(child, g[node]) if (!removed[child] && child != parent) {
        rec(child, node);
        sizes[node] += sizes[child];
      }
    })(centroid, -1);

    each(child, g[centroid]) if (!removed[child]) {
      int child_centroid = rec(child, sizes[child]);
      ans[child_centroid] = centroid + 1;
    }
    return centroid;
  })(0, n);
  wt(ans);
}
