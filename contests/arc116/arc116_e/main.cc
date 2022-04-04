#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "graph.h"

void Main() {
  ints(n, k);
  Graph g(n);
  g.Read();
  wt(BinarySearch<int>(n, 0, [&](int t) {
    auto [closest_marked, farthest_uncovered, sum_child_marked] =
        Fix([&](auto rec, int node, int parent) -> tuple<int, int, int> {
          int closest_marked = big;
          int farthest_uncovered = 0;
          int sum_child_marked = 0;
          each(child, g[node]) {
            if (child == parent) continue;
            auto [child_closest_marked, child_farthest_uncovered,
                  child_marked] = rec(child, node);
            chmin(closest_marked, child_closest_marked + 1);
            chmax(farthest_uncovered, child_farthest_uncovered + 1);
            sum_child_marked += child_marked;
          }
          if (farthest_uncovered == t) {
            // This node needs to be marked.
            closest_marked = 0;
            farthest_uncovered = -1;
            ++sum_child_marked;
            dbg(node + 1, "marked");
          } else {
            if (farthest_uncovered >= 0 &&
                farthest_uncovered + closest_marked <= t) {
              // The farthest uncovered node can be covered by the closest
              // marked node.
              farthest_uncovered = -1;
            }
          }
          dbg(node + 1, closest_marked, farthest_uncovered, sum_child_marked);
          return {closest_marked, farthest_uncovered, sum_child_marked};
        })(0, -1);
    dbg(t, closest_marked, farthest_uncovered, sum_child_marked);
    // There are still some uncovered nodes. It suffices to mark the root node.
    if (farthest_uncovered >= 0) ++sum_child_marked;
    return sum_child_marked <= k;
  }));
}
