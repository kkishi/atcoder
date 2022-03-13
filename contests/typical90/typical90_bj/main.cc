#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> ans;
  V<bool> visited(n);
  VV<int> g(n);
  queue<int> que;
  rep(i, n) {
    ints(a, b);
    --a, --b;
    g[a].pb(i);
    g[b].pb(i);
    if (a == i || b == i) {
      ans.pb(i);
      que.push(i);
      visited[i] = true;
    }
  }
  while (!que.empty()) {
    int i = que.front();
    que.pop();
    each(j, g[i]) {
      if (!visited[j]) {
        visited[j] = true;
        ans.pb(j);
        que.push(j);
      }
    }
  }
  if (sz(ans) != n) {
    wt(-1);
    return;
  }
  reverse(ans);
  each(e, ans) wt(e + 1);
}
