#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct Edge {
  int node;
  int index;
};

int main() {
  rd(int, n);
  vector<vector<Edge>> edges(n + 1);
  rep(i, n) {
    rd(int, a, b);
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
