#include <bits/stdc++.h>

#include "atcoder.h"

struct Edge {
  int node;
  int index;
};

void Main() {
  ints(n);
  VV<Edge> edges(n + 1);
  rep(i, n) {
    ints(a, b);
    edges[a].push_back({b, i});
    edges[b].push_back({a, i});
  }
  set<int> seen;
  seen.insert(1);
  queue<int> que;
  que.push(1);
  map<int, int> color;
  int max_color = 0;
  while (!que.empty()) {
    int here = que.front();
    que.pop();
    set<int> used;
    for (Edge e : edges[here]) used.insert(color[e.index]);
    int c = 1;
    for (Edge e : edges[here]) {
      if (seen.count(e.node)) continue;
      seen.insert(e.node);
      assert(color[e.index] == 0);
      while (used.count(c)) ++c;
      color[e.index] = c;
      chmax(max_color, c);
      ++c;
      que.push(e.node);
    }
  }
  wt(max_color);
  rep(i, n - 1) wt(color[i]);
}
