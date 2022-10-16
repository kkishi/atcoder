#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  Graph g(n);
  g.Read(m);

  V<int> nc(n);
  set<pair<int, int>> st;
  rep(i, n) {
    each(c, g[i]) nc[i] += a[c];
    st.insert({nc[i], i});
  }
  V<bool> rem(n);
  int ans = -big;
  while (!st.empty()) {
    auto it = st.begin();
    auto [cost, node] = *it;
    chmax(ans, cost);
    rem[node] = true;
    each(child, g[node]) {
      if (rem[child]) continue;
      st.erase({nc[child], child});
      nc[child] -= a[node];
      st.insert({nc[child], child});
    }
    st.erase(it);
  }
  wt(ans);
}
