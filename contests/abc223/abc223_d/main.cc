#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> deg(n);
  VV<int> g(n);
  rep(i, m) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    ++deg[b];
  }
  low_priority_queue<int> que;
  rep(i, n) if (deg[i] == 0) que.emplace(i);
  V<int> ans;
  while (!que.empty()) {
    int i = que.top();
    que.pop();
    ans.pb(i + 1);
    each(e, g[i]) {
      --deg[e];
      if (deg[e] == 0) {
        que.emplace(e);
      }
    }
  }
  if (sz(ans) < n) {
    wt(-1);
  } else {
    wt(ans);
  }
}
