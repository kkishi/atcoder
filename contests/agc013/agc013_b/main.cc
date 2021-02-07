#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> to(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  int a = to[0][0];
  V<bool> seen(n);
  seen[0] = true;
  seen[a] = true;
  queue<int> que;
  que.push(0);
  que.push(a);
  V<int> f{a}, b{0};
  while (!que.empty()) {
    int n = que.front();
    que.pop();
    for (int c : to[n]) {
      if (seen[c]) continue;
      seen[c] = true;
      que.push(c);
      (f.back() == n ? f : b).pb(c);
      break;
    }
  }
  reverse(all(b));
  for (int n : f) b.pb(n);
  wt(sz(b));
  each(x, b)++ x;
  wt(b);
}
