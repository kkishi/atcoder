#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read(n);
  V<int> deg(n);
  rep(i, n) deg[i] = sz(g[i]);
  queue<int> que;
  rep(i, n) if (deg[i] == 1) que.push(i);
  set<int> st;  // Nodes that are not in the loop.
  while (!que.empty()) {
    int n = que.front();
    que.pop();
    st.insert(n);
    each(c, g[n]) if (--deg[c] == 1) que.push(c);
  }
  map<int, int> mp;
  rep(i, n) if (!st.count(i)) {
    Fix([&](auto rec, int n, int p) -> void {
      mp[n] = i;
      each(c, g[n]) if (c != p && st.count(c)) rec(c, n);
    })(i, -1);
  }
  ints(q);
  rep(q) {
    ints(x, y);
    wt(mp[x - 1] == mp[y - 1]);
  }
}
