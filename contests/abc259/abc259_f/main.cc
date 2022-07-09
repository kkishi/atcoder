#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  V<int> d(n);
  cin >> d;
  WeightedGraph<int> g(n);
  g.Read();
  vector memo(n, vector(2, -big));
  vector seen(n, vector(2, false));
  wt(Fix([&](auto rec, int node, int parent, int used) -> int {
    if (!seen[node][used]) {
      seen[node][used] = true;
      V<int> diff;
      int sum = 0;
      each(child, weight, g[node]) {
        if (child == parent) continue;
        // Don't use
        int x = rec(child, node, 0);
        sum += x;
        // Use
        if (d[child] > 0) {
          int y = weight + rec(child, node, 1);
          if (y > x) diff.eb(y - x);
        }
      }
      sort(diff, greater{});
      rep(i, min(sz(diff), d[node] - used)) sum += diff[i];
      memo[node][used] = sum;
    }
    return memo[node][used];
  })(0, -1, 0));
}
