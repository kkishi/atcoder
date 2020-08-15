#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, q);
  vector<vector<int>> g(n + 1);
  rep(i, n - 1) {
    rd(int, a, b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<ll> xs(n + 1);
  rep(i, q) {
    rd(ll, p, x);
    xs[p] += x;
  }
  vector<ll> result(n + 1);
  Fix([&](auto dfs, ll x, int node, int parent) -> void {
    x += xs[node];
    result[node] = x;
    for (int child : g[node]) {
      if (child == parent) continue;
      dfs(x, child, node);
    }
  })(0, 1, -1);
  rep(i, n) {
    if (i) cout << " ";
    cout << result[i + 1];
  }
  cout << endl;
}
