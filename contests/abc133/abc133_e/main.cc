#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n, k);
  vector<vector<int>> graph(n + 1);
  rep(i, n - 1) {
    ints(a, b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  wt(Fix([&](auto dfs, int node, int parent, int d1, int d2) -> mint {
    int remaining = k - (d1 + d2);
    if (remaining <= 0) return 0;
    mint ret = remaining;
    for (int child : graph[node]) {
      if (child == parent) continue;
      ret *= dfs(child, node, 1, d1);
      ++d1;
    }
    return ret;
  })(1, -1, 0, 0));
}
