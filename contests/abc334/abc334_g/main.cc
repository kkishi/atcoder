// Based on: https://atcoder.jp/contests/abc334/editorial/8980
#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<998244353>;

std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> LowLink(
    const Graph& g) {
  int n = sz(g);
  std::vector<int> par(n), ord(n, -1), low(n);
  int cur = 0;
  Fix([&](auto rec, int node, int parent) -> void {
    par[node] = parent;
    low[node] = ord[node] = cur++;
    for (int child : g[node]) {
      if (child == parent) continue;
      if (ord[child] == -1) {
        rec(child, node);
        chmin(low[node], low[child]);
      } else {
        chmin(low[node], ord[child]);
      }
    }
  })(0, -1);
  return {par, ord, low};
}

std::vector<Graph> ForestToTrees(const Graph& f) {
  int n = f.size();
  std::vector<int> idx(n, -1);
  std::vector<Graph> gs;
  for (int i = 0; i < n; ++i) {
    if (idx[i] != -1) continue;
    Graph g;
    int cur = 0;
    Fix([&](auto rec, int node) -> void {
      if (idx[node] != -1) return;
      idx[node] = cur++;
      g.push_back({});
      for (int child : f[node]) {
        rec(child);
        g[idx[node]].push_back(idx[child]);
      }
    })(i);
    gs.emplace_back(g);
  }
  return gs;
}

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  int n = h * w;
  Graph g(n);  // s[i][j] <=> g[i*w+j]
  auto id = [&](int i, int j) { return i * w + j; };
  rep(i, h) rep(j, w) {
    each(ni, nj, adjacent(i, j)) if (inside(ni, nj, h, w)) {
      if (s[i][j] == '#' && s[ni][nj] == '#') {
        g[id(i, j)].eb(id(ni, nj));
      }
    }
  }

  int reds = 0;
  each(e, s) each(e, e) if (e == '.')++ reds;

  std::vector<Graph> gs = ForestToTrees(g);
  int connected_components = sz(gs) - reds;

  int one_greens = n - reds;  // The number of gs[i] which consists of one #.
  each(g, gs) if (sz(g) != 1) one_greens -= sz(g);

  mint sum = one_greens * (connected_components - 1);
  each(g, gs) {
    if (sz(g) == 1) continue;  // Skip reds and one-greens.
    auto [par, ord, low] = LowLink(g);
    rep(node, sz(g)) {
      int c = par[node] != -1;
      each(child, g[node]) if (par[child] == node && ord[node] <= low[child]) {
        ++c;
      }
      sum += connected_components - 1 + c;
    }
  }
  wt(sum / (n - reds));
}
