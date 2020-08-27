#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  VV<int> to(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  V<int> color(n, -1);
  color[0] = 0;
  color[n - 1] = 1;

  // Move towards the opponent as much as possible.
  Fix([&](auto rec, int node, int parent, int df) -> int {
    if (node == n - 1) return 0;
    for (int child : to[node]) {
      if (child == parent) continue;
      int d = rec(child, node, df + 1);
      if (d >= 0) {
        int ds = d + 1;
        if (color[node] == -1) {
          color[node] = df <= ds ? 0 : 1;
        }
        return d + 1;
      }
    }
    return -1;
  })(0, -1, 0);

  // Coloring of the remaining cells is determined.
  rep(i, n) if (color[i] != -1) {
    Fix([&](auto rec, int node, int parent) -> void {
      for (int child : to[node]) {
        if (child == parent) continue;
        if (color[child] != -1) continue;
        color[child] = color[node];
        rec(child, node);
      }
    })(i, -1);
  }

  int f = count(all(color), 0);
  int s = count(all(color), 1);
  assert(f + s == n);

  wt(f > s ? "Fennec" : "Snuke");
}
