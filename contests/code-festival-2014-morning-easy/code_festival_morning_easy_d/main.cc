#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);

  VV<int> v(100001);
  rep(n) {
    ints(x, y);
    v[x].pb(y);
  }

  V<int> a(100001);
  rep(m) {
    ints(ai);
    ++a[ai];
  }

  low_priority_queue<int> que;
  int ans = 0;
  rep(i, 100001) {
    for (int vi : v[i]) que.push(vi);
    while (!que.empty() && que.top() < i) que.pop();
    rep(a[i]) {
      if (!que.empty() && que.top() >= i) {
        ++ans;
        que.pop();
      }
    }
  }
  wt(ans);
}
