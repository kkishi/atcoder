#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> bs(n);
  rep(n) {
    ints(a, b);
    bs[a - 1].pb(b);
  }
  priority_queue<int> que;
  int ans = 0;
  rep(i, n) {
    each(b, bs[i]) que.push(b);
    ans += que.top();
    que.pop();
    wt(ans);
  }
}
