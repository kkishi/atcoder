// NOTE: This solution is not correct.
#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, k);
  VV<int> g(n);
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  V<int> height(n);
  V<int> weight(n);
  Fix([&](auto rec, int node, int parent) -> pair<int, int> {
    int h = 0;
    int w = 1;
    each(child, g[node]) {
      if (child != parent) {
        auto [ch, cw] = rec(child, node);
        chmax(h, ch + 1);
        w += cw;
      }
    }
    height[node] = h;
    weight[node] = w;
    return {h, w};
  })(0, -1);
  V<int> cnt(n);
  VV<int> nodes(n);
  rep(i, n) {
    ++cnt[height[i]];
    nodes[height[i]].pb(i);
  }
  wt(BinarySearch<int>(n, 0, [&](int t) {
    int sum = 0;
    V<int> marked;
    for (int i = t; i < n; i += t * 2 + 1) {
      sum += cnt[i];
      each(e, nodes[i]) marked.pb(e);
    }
    V<int> dist(n, big);
    queue<int> que;
    each(e, marked) {
      dist[e] = 0;
      que.push(e);
    }
    while (!que.empty()) {
      int node = que.front();
      que.pop();
      each(child, g[node]) if (chmin(dist[child], dist[node] + 1)) {
        que.push(child);
      }
    }
    bool has_unreachable = false;
    rep(i, n) if (dist[i] > t) { has_unreachable = true; }
    if (has_unreachable) ++sum;
    return sum <= k;
  }));
}
